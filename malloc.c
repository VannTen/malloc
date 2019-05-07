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
#include "constants.h"
#include <stddef.h>
#include <assert.h>

static size_t	get_size_category(size_t const size)
{
	return ((size - sizeof (struct s_free_node)) / ALIGNMENT + 1);
}

static void	recategorize_page(struct s_alloc_zone const **page_location,
		size_t const old_category)
{
	size_t				new_category;

	new_category = page_size_category(*page_location);
	if (new_category < old_category)
	{
		while (new_category != 0
				&& g_alloc_zone.block_by_size[new_category] != NULL)
			new_category--;
		if (g_alloc_zone.block_by_size[new_category] != NULL)
			g_alloc_zone.block_by_size[new_category] = *page_location;
		else
			list_add(
					g_alloc_zone.partially_used_pages[old_category <= TINY_MAX],
					&(*page_location)->list_node);
		*page_location = NULL;
	}
}

static int			size_fits(void const *page_list_node, void const *size_cat)
{
	return (page_size_category(
				page_from_list(page_list_node)) >= *(size_t*)size_cat);
}

static s_alloc_zone	*get_page(size_t const size_category)
{
	int	tiny_page const = size_category <= TINY_MAX;
	struct s_alloc_zone	*new_page;

	if (g_alloc_zone.partially_used_pages[tiny_page] != NULL)
		new_page = list_remove_if(&g_alloc_zone.partially_used_pages[tiny_page],
				size_fits, &size_category);
	else
	{
		new_page = create_alloc_zone(tiny_page ? tiny_page_size() : small_page_size());
		rbtree_insert(&g_alloc_zones.page_tree, new_page, page_cmp);
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
	while (g_alloc_zone.block_by_size[size_category] == NULL
			&& size_category != max_category)
		size_category++;
	used_page = &g_alloc_zone.block_by_size[size_category];
	if (*used_page == NULL)
		*used_page = get_page(size_category);
	new_address = (void*)get_first_fit(*used_page);
	recategorize_page(used_page, size_category);
	return (new_address);
}

void	*malloc(size_t const size)
{
	void				*client_address;

	if (size > small_size_limit())
		client_address = alloc_large(size);
	else
		client_address = alloc_tiny_small(size);
	return (client_address);
}
