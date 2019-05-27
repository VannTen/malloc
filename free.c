/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 17:47:28 by                   #+#    #+#             */
/*   Updated: 2019/05/09 17:47:28 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_node.h"
#include "constants.h"
#include "malloc_structures.h"
#include "rb_tree.h"
#include "list.h"
#include <stdint.h>
#include <assert.h>

static int	address_page_position(void const *_page, void const *address)
{
	struct s_alloc_zone const *page = _page;

	if ((uintptr_t)page > (uintptr_t)address)
		return (1);
	else if ((uintptr_t)page + page->size > (uintptr_t)address)
		return (0);
	else
		return (-1);
}

static int	address_is_valid(void const *address)
{
	struct s_alloc_zone const	*page;

	if ((uintptr_t)address % ALIGNMENT != 0)
		return (0);
	page = (struct s_alloc_zone const *)btree_search(g_alloc_zones.page_tree,
							address,
							address_page_position);
	if (page == NULL)
		return (0);
	return (address_exists_in_page(address, page) && address_is_taken(address));
}

static int	same_page(void const *page, struct s_list const *page_list_node)
{
	return (page == page_from_list_node(page_list_node));
}

void		remove_from_incomplete_pages(struct s_alloc_zone const *page)
{
	size_t	index;

	index = 0;
	while (index <= SMALL_MAX && g_alloc_zones.block_by_size[index] != page)
		index++;
	if (index <= SMALL_MAX)
		g_alloc_zones.block_by_size[index] = NULL;
	else
	{
		index = 0;
		while (index < 2
				&& NULL != list_remove_if(
					&g_alloc_zones.partially_used_pages[index],
					page,
					same_page)
			 )
			index++;
	}
}

void		free(void *address)
{
	struct s_alloc_zone const	*cleared_page;

	if (address == NULL)
		return ;
	assert(address_is_valid(address));
	cleared_page = free_defrag(address);
	if (cleared_page != NULL)
	{
		remove_from_incomplete_pages(cleared_page);
		cleared_page = rbtree_remove(
				&g_alloc_zones.page_tree, address, address_page_position);
		assert(cleared_page != NULL);
	}
}
