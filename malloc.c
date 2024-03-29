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

#include "malloc.h"
#include "small_tiny_alloc.h"
#include "alloc_zone.h"
#include "malloc_lock.h"
#include "constants.h"
#include <stddef.h>
#include <assert.h>
#include <unistd.h>
#include <stdint.h>

static int					size_overflow(size_t const size)
{
	return (SIZE_MAX - offset_zone_start_first_address() < size);
}

static struct s_free_node	*alloc_large(size_t const size)
{
	struct s_alloc_zone	*new_page;
	size_t				page_size;
	struct s_free_node	*alloc_node;

	if (size_overflow(size))
		return (NULL);
	page_size =
		((offset_zone_start_first_address() + size - 1)
		/ getpagesize() + 1)
		* getpagesize();
	alloc_node = NULL;
	malloc_write_lock();
	new_page = create_zone(page_size);
	if (new_page != NULL)
	{
		new_page->page_type = LARGE;
		get_first_node(new_page)->free = FALSE;
		new_page->total_free_size = 0;
		alloc_node = get_first_node(new_page);
	}
	malloc_unlock();
	return (alloc_node);
}

void						*malloc(size_t const size)
{
	struct s_free_node const	*selected_node;

	if (size > small_size_limit())
		selected_node = alloc_large(size);
	else
		selected_node = alloc_tiny_small(size);
	assert(malloc_pages_in_good_state());
	return ((void*)get_public_address(selected_node));
}
