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

struct s_free_node	*get_first_node(struct s_alloc_zone const * const zone)
{
	return ((void*)((char*)zone
			+ offset_zone_start_first_free_node()));
}
