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
#include "constants.h"
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
		new_page->page_type = LARGE;
		get_first_node(new_page)->free = FALSE;
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
	assert(malloc_pages_in_good_state());
	return ((void*)get_public_address(selected_node));
}
