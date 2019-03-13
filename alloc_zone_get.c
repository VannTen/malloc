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

#include "alloc_zone.h"
#include "free_node.h"

struct s_free_node	*get_first_node(struct s_alloc_zone const * const zone)
{
	return ((void*)((char*)zone
			+ offset_zone_start_first_free_node()));
}

size_t	offset_zone_start_first_address( void )
{
	return (round_up_to_multiple(
				sizeof (struct s_alloc_zone) + sizeof(struct s_free_node),
				LOG_2_ALIGN));
}

size_t	offset_zone_start_first_free_node( void )
{
	return (offset_zone_start_first_address() - sizeof(struct s_free_node));
}
