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
#include "constants.h"
#include <stddef.h>
#include <assert.h>

static int					page_is_good_candidate(
		struct s_alloc_zone const *const page,
		size_t const size)
{
	return (page->total_free_size >= size);
}

static void					*get_address(
		struct s_double_list const *const list,
		void const *const v_size)
{
	struct s_alloc_zone *const	page = page_from_list_node(list);
	size_t const				size = *(size_t const *)v_size;

	if (page_is_good_candidate(page, size))
		return (get_first_fit(page, size));
	else
		return (NULL);
}

struct s_free_node const	*alloc_tiny_small(size_t const size)
{
	struct s_free_node const	*new_address;
	struct s_double_list		**alloc_type;
	struct s_alloc_zone			*new_page;

	alloc_type = size <= tiny_size_limit()
		? &g_alloc_zones.tinies : &g_alloc_zones.smalls;
	new_address = d_list_find(*alloc_type, get_address, &size);
	if (new_address == NULL)
	{
		new_page = create_zone(page_size(alloc_type == &g_alloc_zones.tinies
					? TINY_MAX : SMALL_MAX));
		if (new_page != NULL)
		{
			d_list_insert_back(alloc_type, &new_page->list);
			new_address = d_list_find_back(*alloc_type, get_address, &size);
		}
	}
	return (new_address);
}
