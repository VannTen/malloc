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
#include "bool.h"
#include "constants.h"
#include <assert.h>
#include <stddef.h>

size_t						merge_with_next_nodes(struct s_free_node *node)
{
	size_t	freed_space;

	freed_space = 0;
	while (next_node(node)->free && !is_last_node(node))
	{
		node->next_offset += next_node(node)->next_offset;
		freed_space += sizeof(*node);
	}
	return (freed_space);
}

static size_t				defrag_to_last_node(
		struct s_free_node *node)
{
	assert(node->free);
	return (merge_with_next_nodes(node));
}

static struct s_free_node	*defragment_page_from(
		struct s_free_node *node, size_t *const freed_space)
{
	while (1)
	{
		if (node->free)
			*freed_space += defrag_to_last_node(node);
		if (is_last_node(node))
			break ;
		node = next_node(node);
	}
	return (node);
}

struct s_alloc_zone			*free_defrag(void *ptr)
{
	struct s_free_node	*node;
	struct s_free_node	*first_node;
	struct s_alloc_zone	*page;
	size_t				freed_space;

	node = ((struct s_free_node *)ptr) - 1;
	node->free = TRUE;
	freed_space = node_size(node);
	node = defragment_page_from(node, &freed_space);
	assert(is_last_node(node));
	first_node = next_node(node);
	page = get_page_from_first_node(first_node);
	(void)defragment_page_from(first_node, &freed_space);
	page->total_free_size += freed_space;
	return (is_last_node(first_node) ? page : NULL);
}
