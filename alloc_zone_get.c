/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_zone_get.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 17:12:23 by                   #+#    #+#             */
/*   Updated: 2019/03/11 17:12:23 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "alloc_zone.h"
#include "free_node.h"
#include <stddef.h>

struct s_free_node	*get_first_node(struct s_alloc_zone const * const zone)
{
	return ((void*)((char*)zone
			+ offset_zone_start_first_free_node()));
}

size_t				nb_free_node(struct s_alloc_zone const * const zone)
{
	size_t	nb_free_node;
	struct s_free_node const * node;

	nb_free_node = 1;
	node = get_first_node(zone);
	while (!is_last_node(node))
	{
		nb_free_node++;
		node = node->next;
	}
	return (nb_free_node);
}

void			*end_of_zone(struct s_alloc_zone const * const start_of_zone)
{
	return ((char*)start_of_zone + start_of_zone->size);
}
