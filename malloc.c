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

#include "small_tiny_alloc.h"
#include "malloc_structures.h"
#include "malloc_intern_debug.h"
#include "alloc_zone.h"
#include "constants.h"
#include "rb_tree.h"
#include <stddef.h>
#include <assert.h>
#include <unistd.h>

static struct s_free_node	*alloc_large(size_t const size)
{
	struct s_alloc_zone	*new_page;
	size_t				page_size;

	page_size =
		((offset_zone_start_first_address() + size - 1)
		/ getpagesize() + 1)
		* getpagesize();
	new_page = create_zone(page_size);
	if (new_page != NULL)
	{
		rbtree_insert(&g_alloc_zones.page_tree,
				&new_page->tree_node, alloc_zone_cmp);
		get_first_node(new_page)->free = FALSE;
		new_page->biggest_free_size = LARGE_MAGIC_NUMBER;
		return (get_first_node(new_page));
	}
	else
		return (NULL);
}

void						*malloc(size_t const size)
{
	struct s_free_node const	*selected_node;

	if (size > small_size_limit())
		selected_node = alloc_large(size);
	else
		selected_node = alloc_tiny_small(size);
	assert(!large_in_bad_places(&g_alloc_zones));
	return ((void*)get_public_address(selected_node));
}
