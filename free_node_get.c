/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_node_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 13:54:00 by                   #+#    #+#             */
/*   Updated: 2019/03/13 13:54:00 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_node.h"
#include "alloc_zone.h"
#include "constants.h"

void const	*get_public_address(struct s_free_node const * const node)
{
	return (node + 1);
}

static	struct s_alloc_zone *zone_start(struct s_free_node const * last_node)
{
	return ((void*)((char*)last_node->next - offset_zone_start_first_free_node()));
}

t_bool	is_last_node(struct s_free_node const * node)
{
	return (node->next <= node);
}

size_t	node_size(struct s_free_node const * const node)
{
	if (is_last_node(node))
		return ((char*)node
				- ((char*)zone_start(node) + size_of_zone));
	else
		return ((char*)node->next - (char*)node - sizeof *node);
}

