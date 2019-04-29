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
	{
		*used_page = create_zone(page_size(max_category));
		if (*used_page == NULL)
			return (NULL);
	}
	new_address = (void*)get_first_fit( *used_page);
	if (page_size_cat(*used_page != size_category))
	{
		list_add(&g_alloc_zone.block_by_size[page_size_cat(*used)],
				 list_pop(used));
	}
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
