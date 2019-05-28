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

#include "constants.h"
#include "alloc_zone.h"
#include "free_node.h"
#include <stddef.h>
#include <assert.h>

int					address_exists_in_page(
		void const *address,
		struct s_alloc_zone const *page)
{
	struct s_free_node const *node;

	node = get_first_node(page);
	while (get_public_address(node) != address && !is_last_node(node))
		node = next_node(node);
	return (get_public_address(node) == address);
}

struct s_free_node	*get_first_node(struct s_alloc_zone const * const zone)
{
	assert(zone != NULL);
	return ((void*)((char*)zone
			+ offset_zone_start_first_free_node()));
}

static size_t		nb_free_intern(
		struct s_alloc_zone const * const zone,
		t_bool counting_occupied_nodes)
{
	size_t	nb_free_node;
	struct s_free_node const * node;

	nb_free_node = 1;
	node = get_first_node(zone);
	while (!is_last_node(node))
	{
		if (counting_occupied_nodes || node->free)
			nb_free_node++;
		node = next_node(node);
	}
	return (nb_free_node);
}

size_t				nb_free_node(struct s_alloc_zone const * const zone)
{
	return (nb_free_intern(zone, FALSE));
}

size_t				nb_node(struct s_alloc_zone const * const zone)
{
	return (nb_free_intern(zone, TRUE));
}

void			*end_of_zone(struct s_alloc_zone const * const start_of_zone)
{
	return ((char*)start_of_zone + start_of_zone->size);
}

size_t			page_size_category(struct s_alloc_zone const *page)
{
	//assert(!is_large_page(page)) TODO
	return (page->biggest_free_size);
}
