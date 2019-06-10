/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placeholder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 11:10:44 by mgautier          #+#    #+#             */
/*   Updated: 2019/05/28 11:10:44 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_node.h"
#include "constants.h"
#include "malloc_structures.h"
#include "malloc.h"
#include "rb_tree.h"
#include "list.h"
#include <stdint.h>
#include <assert.h>
#include <sys/mman.h>

static int	address_page_position(void const *v_page, void const *address)
{
	struct s_alloc_zone const *page = v_page;

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

void		free(void *address)
{
	struct s_alloc_zone			*cleared_page;
	int							ret_val;

	if (address == NULL || !address_is_valid(address))
		return ;
	assert(address_is_valid(address));
	cleared_page = free_defrag(address);
	if (cleared_page != NULL
			&& ((is_tiny(cleared_page)
					&& &cleared_page->list != g_alloc_zones.tinies)
				|| (is_small(cleared_page)
					&& &cleared_page->list != g_alloc_zones.smalls)))
	{
		d_list_remove(&cleared_page->list);
		cleared_page = rbtree_remove(
				&g_alloc_zones.page_tree, address, address_page_position);
		assert(cleared_page != NULL);
		ret_val = munmap(cleared_page, cleared_page->size);
		assert(ret_val == 0);
	}
	assert(malloc_pages_in_good_state());
}
