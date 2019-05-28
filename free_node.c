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

static void					defrag_to_last_node(
		struct s_free_node *node)
{
	assert(node->free);
	while (next_node(node)->free && !is_last_node(node))
		node->next_offset += next_node(node)->next_offset;
}

static struct s_alloc_zone	*defragment_node(struct s_free_node *node)
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

struct s_alloc_zone			*free_defrag(void *ptr)
{
	struct s_free_node *const node = (struct s_free_node *)ptr - 1;

	free_node(ptr);
	return (defragment_node(node));
}

void						free_node(void *ptr)
{
	struct s_free_node *const node = (struct s_free_node *)ptr - 1;

	node->free = TRUE;
}
