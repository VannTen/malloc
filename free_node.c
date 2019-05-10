/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:31:53 by                   #+#    #+#             */
/*   Updated: 2019/03/14 17:31:53 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_node.h"
#include "bool.h"
#include "constants.h"
#include <assert.h>
#include <stddef.h>

void const	*publish_address(struct s_free_node * node)
{
	assert(node->free);
	node->free = FALSE;
	return (get_public_address(node));
}

static void		defrag_to_last_node(struct s_free_node * node)
{
	assert(node->free);
	while (next_node(node)->free && !is_last_node(node))
		node->next_offset += next_node(node)->next_offset;
}

static struct s_alloc_zone const	*defragment_node(struct s_free_node * node)
{
	struct s_free_node	*first_node;

	assert(node->free);
	defrag_to_last_node(node);
	if (next_node(node)->free)
	{
		first_node = next_node(node);
		defrag_to_last_node(first_node);
		if (is_last_node(first_node))
			return (get_page_from_first_node(first_node));
	}
	return (NULL);
}

struct s_alloc_zone const	*free_defrag(void *ptr)
{
	struct s_free_node * const node = (struct s_free_node *)ptr - 1;

	free_node(ptr);
	return (defragment_node(node);
}

void		free_node(void *ptr)
{
	struct s_free_node * const node = (struct s_free_node *)ptr - 1;

	node->free = TRUE;
}
