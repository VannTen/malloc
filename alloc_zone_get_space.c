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

#include "alloc_zone.h"
#include "free_node.h"
#include <stddef.h>

static size_t	alloc_zone_space(struct s_alloc_zone const *const zone,
		int const counting_free)
{
	struct s_free_node const	*node;
	size_t						size_total;

	node = get_first_node(zone);
	size_total = 0;
	while (1)
	{
		if ((!counting_free) ^ (!!node->free))
			size_total += node_size(node);
		if (is_last_node(node))
			break ;
		node = next_node(node);
	}
	return (size_total);
}

size_t			alloc_zone_free_space(struct s_alloc_zone const *const zone)
{
	return (alloc_zone_space(zone, 1));
}

size_t			alloc_zone_taken_space(struct s_alloc_zone const *const zone)
{
	return (alloc_zone_space(zone, 1));
}

size_t			alloc_zone_all_space(struct s_alloc_zone const *const zone)
{
	return (alloc_zone_free_space(zone) + alloc_zone_taken_space(zone));
}
