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
#include <assert.h>

void const	*publish_address(struct s_free_node * node)
{
	assert(node->free);
	node->free = FALSE;
	return (get_public_address(node));
}

static void		defrag_to_last_node(struct s_free_node * node)
{
	assert(node->free);
	while (node->next->free && !is_last_node(node))
		node->next = node->next->next;
}

static void		defragment_node(struct s_free_node * node)
{
	assert(node->free);
	defrag_to_last_node(node);
	if (node->next->free)
		defrag_to_last_node(node->next);
}

void		free_defrag(void *ptr)
{
	struct s_free_node * const node = (struct s_free_node *)ptr - 1;

	free_node(ptr);
	defragment_node(node);
}

void		free_node(void *ptr)
{
	struct s_free_node * const node = (struct s_free_node *)ptr - 1;

	node->free = TRUE;
}
