/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_first_fit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 13:30:59 by                   #+#    #+#             */
/*   Updated: 2019/02/25 13:30:59 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alloc_zone.h"
#include "free_node.h"
#include "bool.h"
#include "constants.h"
#include <stddef.h>
#include <assert.h>

static t_bool	node_has_enough_space(struct s_free_node const * const node,
		size_t space)
{
	return (node_size(node) >= space && node->free);
}

static void	carve_node(struct s_free_node * node, size_t size_required)
{
	struct s_free_node * new_node;

	assert(node_has_enough_space(node, size_required)
			&& node_size(node)
				>= size_required + sizeof *node + MIN_ALLOC_SPACE);
	new_node = (struct s_free_node *)((char*)(node + 1)
			+ round_up_to_multiple(size_required, ft_pow(2, LOG_2_ALIGN)));
	new_node->next_offset = (char*)next_node(node) - (char*)new_node;
	new_node->free = TRUE;
	node->next_offset = (char*)new_node - (char*)node;
}

void const	*get_first_fit(struct s_alloc_zone *zone, size_t size_required)
{
	struct s_free_node *	node;

	node = get_first_node(zone);
	while (!node_has_enough_space(node, size_required))
	{
		node = next_node(node);
		if (is_last_node(node))
			break ;
	}
	if (node_size(node) >= size_required + sizeof *node + MIN_ALLOC_SPACE)
		carve_node(node, size_required);
	return (node_has_enough_space(node, size_required)
			? publish_address(node) : NULL);
}
