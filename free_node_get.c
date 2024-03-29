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

#include "free_node.h"
#include "alloc_zone.h"
#include "constants.h"

int							address_is_taken(void const *address)
{
	return (!((struct s_free_node const *)address - 1)->free);
}

static struct s_alloc_zone	*zone_start(struct s_free_node const *last_node)
{
	return ((void*)((char*)next_node(last_node)
				- offset_zone_start_first_free_node()));
}

t_bool						is_last_node(struct s_free_node const *node)
{
	return (node->next_offset <= 0);
}

size_t						node_size(struct s_free_node const *const node)
{
	char const	*end_of_node;

	end_of_node = (char*)is_last_node(node)
		? end_of_zone(zone_start(node)) : next_node(node);
	return (end_of_node - (char const *)(node + 1));
}

struct s_free_node			*next_node(struct s_free_node const *node)
{
	return ((struct s_free_node*)(((char*)node) + node->next_offset));
}
