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
#include "max.h"
#include <stddef.h>
#include <assert.h>
#include <stdint.h>

static t_bool	node_has_enough_space(struct s_free_node const * const node,
		size_t space)
{
	return (node_size(node) >= space && node->free);
}

static void	carve_node(struct s_free_node * node, size_t size_required)
{
	struct s_free_node * new_node;

	assert(node->free);
	assert(node_size(node) >= size_required + sizeof *node + MIN_ALLOC_SPACE);
	new_node = (struct s_free_node *)((char*)(node)
			+ (size_to_size_category(size_required) + 1) * ALIGNMENT);
	new_node->next_offset = (char*)next_node(node) - (char*)new_node;
	new_node->free = TRUE;
	node->next_offset = (char*)new_node - (char*)node;
	assert((uintptr_t)get_public_address(new_node) % ALIGNMENT == 0);
	assert(node_has_enough_space(node, size_required));
}

static void	update_page_cat(
		struct s_alloc_zone *zone,
		struct s_free_node const *node)
{
	size_t	max_size;

	max_size = 0;
	while (node_size_category(node) < zone->biggest_free_size
			&& !is_last_node(node))
	{
		max_size = size_t_max(node_size_category(node), max_size);
		node = next_node(node);
	}
	if (node_size_category(node) < zone->biggest_free_size)
		zone->biggest_free_size = max_size;
}

void const	*get_first_fit(struct s_alloc_zone *zone, size_t size_required)
{
	struct s_free_node *	node;

	node = get_first_node(zone);
	while (!is_last_node(node) && !node_has_enough_space(node, size_required))
		node = next_node(node);
	if (node->free
			&& node_size(node)
			>= size_required + sizeof *node + MIN_ALLOC_SPACE)
	{
		carve_node(node, size_required);
		if (node_size_category(next_node(node)) < zone->biggest_free_size)
			update_page_cat(zone, next_node(node));
	}
	return (node_has_enough_space(node, size_required)
			? publish_address(node) : NULL);
}
