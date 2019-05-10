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
#include <stdint.h>
#include <assert.h>

static int	address_page_position(void const *address, void const *_page)
{
	struct s_alloc_zone const *page = _page;

	if ((uintptr_t)page > (uintptr_t)address)
		return (-1);
	else if ((uintptr_t)page + page->size > (uintptr_t)address)
		return (0);
	else
		return (-1);
}

static int	address_is_valid(void const *address)
{
	return ((uintptr_t)address % ALIGNMENT == 0
			&& btree_search(g_alloc_zones.page_tree,
							address,
							address_page_position) != NULL
			&& !((struct s_free_node const *)address)->free);
}

void		remove_from_incomplete_pages(struct s_alloc_zone const *page)
{
	size_t	index;

	index = 0;
	while (index <= SMALL_MAX && g_alloc_zones.block_by_size[index] != page)
		index++;
	if (index <= SMALL_MAX)
		g_alloc_zones.block_by_size[index] = NULL;
	else if (list_remove_if(g_alloc_zones.partially_used_pages[0]) != NULL)
		;
	else
		list_remove_if(g_alloc_zones.partially_used_pages[1]);

}

void		free(void *address)
{
	struct s_alloc_zone const	*cleared_page;

	assert(address_is_valid(address));
	cleared_page = free_defrag(address);
	if (cleared_page != NULL)
	{
		rbtree_remove(&g_alloc_zones.page_tree, address, address_page_position);
		remove_from_incomplete_pages(cleared_page);
	}
}
