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
	assert(node_size_category(node) > size_to_size_category(size_required));
	new_node = (struct s_free_node *)((char*)(node)
			+ (size_to_size_category(size_required)) * ALIGNMENT);
	new_node->next_offset = (char*)next_node(node) - (char*)new_node;
	new_node->free = TRUE;
	node->next_offset = (char*)new_node - (char*)node;
	assert((uintptr_t)get_public_address(new_node) % ALIGNMENT == 0);
	assert(node_has_enough_space(node, size_required));
}

static size_t	new_page_category(size_t max_size, size_t old_cat)
{
	if (max_size >= page_smallest_category(old_cat))
		return (max_size);
	else
		return (0);
}

static void	update_page_cat(
		struct s_alloc_zone *zone,
		struct s_free_node const *node)
{
	size_t	max_size;

	max_size = 0;
	while (node_size_category(node) < zone->biggest_free_size || !node->free)
	{
		if (node->free)
			max_size = size_t_max(node_size_category(node), max_size);
		if (is_last_node(node))
			break ;
		node = next_node(node);
	}
	if (node_size_category(node) < zone->biggest_free_size || !node->free)
		zone->biggest_free_size = new_page_category(
				max_size,
				zone->biggest_free_size);
}

int							carving_may_change_page_cat(
		struct s_free_node const *node,
		size_t const page_cat)
{
	return (node_size_category(next_node(node)) < page_cat
			&& node_size_category(next_node(node)) + node_size_category(node)
			>= page_cat);
}

struct s_free_node const	*get_first_fit(
		struct s_alloc_zone *zone,
		size_t size_required)
{
	struct s_free_node *	node;
	int						may_update_page_cat;

	node = get_first_node(zone);
	may_update_page_cat = FALSE;
	while (!is_last_node(node) && !node_has_enough_space(node, size_required))
		node = next_node(node);
	if (node->free)
	{
		if (node_size_category(node) > size_to_size_category(size_required))
		{
			carve_node(node, size_required);
			may_update_page_cat = carving_may_change_page_cat(node, zone->biggest_free_size);
		}
		if (node_size(node) >= size_required)
		{
			node->free = FALSE;
			may_update_page_cat = may_update_page_cat
				|| zone->biggest_free_size == node_size_category(node);
		}
		else
			node = NULL;
	}
	if (may_update_page_cat)
		update_page_cat(zone, node);
	return (node);
}
