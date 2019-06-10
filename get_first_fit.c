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
#include "bool.h"
#include "constants.h"
#include "max.h"
#include <stddef.h>
#include <assert.h>
#include <stdint.h>

void				carve_node(
		struct s_free_node *const node, size_t const size_required)
{
	struct s_free_node *new_node;

	assert(node_size_category(node) > size_to_size_category(size_required));
	new_node = (struct s_free_node *)((char*)(node)
			+ (size_to_size_category(size_required)) * ALIGNMENT);
	new_node->next_offset = (char*)next_node(node) - (char*)new_node;
	new_node->free = TRUE;
	node->next_offset = (char*)new_node - (char*)node;
	assert((uintptr_t)get_public_address(new_node) % ALIGNMENT == 0);
	assert(node_size(node) >= size_required);
}

static void			carve_free_node(
		struct s_free_node *const node,
		size_t const size_required)
{
	assert(node->free);
	carve_node(node, size_required);
	assert(node->free);
}

struct s_free_node	*get_first_fit(
		struct s_alloc_zone *zone,
		size_t size_required)
{
	struct s_free_node	*node;
	size_t				size_taken;

	node = get_first_node(zone);
	while (!is_last_node(node)
			&& !(node->free && node_size(node) >= size_required))
		node = next_node(node);
	if (node->free && node_size(node) >= size_required)
	{
		size_taken = 0;
		if (node_size_category(node) > size_to_size_category(size_required))
		{
			carve_free_node(node, size_required);
			size_taken += sizeof(*node);
		}
		node->free = FALSE;
		size_taken += node_size(node);
		zone->total_free_size -= size_taken;
	}
	else
		node = NULL;
	return (node);
}
