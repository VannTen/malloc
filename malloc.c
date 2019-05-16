/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 14:06:29 by                   #+#    #+#             */
/*   Updated: 2019/04/27 14:06:29 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_structures.h"
#include "free_node.h"
#include "alloc_zone.h"
#include "constants.h"
#include "list.h"
#include "rb_tree.h"
#include <assert.h>
#include <stddef.h>
#include <unistd.h>

static size_t	get_size_category(size_t const size)
{
	return (size / ALIGNMENT
			+ size / (ALIGNMENT - sizeof (struct s_free_node) + 1));
}

static void	recategorize_page(struct s_alloc_zone **page_location,
		size_t const old_category)
{
	size_t				new_category;

	new_category = page_size_category(*page_location);
	if (new_category < old_category)
	{
		while (new_category != 0
				&& g_alloc_zones.block_by_size[new_category] != NULL)
			new_category--;
		if (g_alloc_zones.block_by_size[new_category] == NULL)
			g_alloc_zones.block_by_size[new_category] = *page_location;
		else
			list_add_start(
					&g_alloc_zones.partially_used_pages[old_category <= TINY_MAX],
					&(*page_location)->list);
		*page_location = NULL;
	}
}

static int			size_fits(
		void const *size_cat,
		struct s_list const *page_list_node)
{
	return (page_size_category(page_from_list_node(page_list_node))
			>= *(size_t const*)size_cat);
}

static struct s_alloc_zone	*get_page(size_t const size_category)
{
	int const			tiny_page = size_category <= TINY_MAX;
	struct s_alloc_zone	*new_page;

	if (g_alloc_zones.partially_used_pages[tiny_page] != NULL)
		new_page = (struct s_alloc_zone *)page_from_list_node(
				list_remove_if(&g_alloc_zones.partially_used_pages[tiny_page],
					&size_category, size_fits));
	else
	{
		new_page = create_zone(tiny_page ? tiny_page_size() : small_page_size());
		rbtree_insert(&g_alloc_zones.page_tree, &new_page->tree_node, alloc_zone_cmp);
	}
	return (new_page);
}

static void	*alloc_tiny_small(size_t const size)
{
	size_t				size_category;
	size_t				max_category;
	void				*new_address;
	struct s_alloc_zone	**used_page;

	size_category = get_size_category(size);
	assert(size_category <= SMALL_MAX);
	max_category = size_category <= TINY_MAX ? TINY_MAX : SMALL_MAX;
	while (g_alloc_zones.block_by_size[size_category] == NULL
			&& size_category != max_category)
		size_category++;
	used_page = &g_alloc_zones.block_by_size[size_category];
	if (*used_page == NULL)
		*used_page = get_page(size_category);
	new_address = (void*)get_first_fit(*used_page, size);
	recategorize_page(used_page, size_category);
	return (new_address);
}

static void	*alloc_large(size_t const size)
{
	struct s_alloc_zone	*new_page;
	size_t				page_size;

	page_size =
		((offset_zone_start_first_address() + size - 1)
		 / getpagesize() + 1)
		* getpagesize();
	new_page = create_zone(page_size);
	if (new_page != NULL)
		rbtree_insert(&g_alloc_zones.page_tree,
				&new_page->tree_node, alloc_zone_cmp);
	return (new_page);
}

void	*malloc(size_t const size)
{
	void				*client_address;

	write(STDOUT_FILENO, "malloc\n", sizeof("malloc\n"));
	if (size > small_size_limit())
		client_address = alloc_large(size);
	else
		client_address = alloc_tiny_small(size);
	return (client_address);
}
