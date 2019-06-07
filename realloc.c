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
#include "memutils.h"
#include <stdlib.h>

static int	resize_node(struct s_free_node *const node, size_t const size)
{
	if (!is_last_node(node) && next_node(node)->free)
	{
		merge_with_next_nodes(next_node(node));
		if (node_size(node) + node_size(next_node(node)) + sizeof(*node)
				>= size)
		{
			merge_with_next_nodes(node);
			return (1);
		}
	}
	return (0);
}

void		*realloc(void *const allocated_ptr, size_t const size)
{
	struct s_free_node *const	node = get_node_from_address(allocated_ptr);
	void						*new_ptr;

	if (node != NULL && (size <= node_size(node) || resize_node(node, size)))
		return (allocated_ptr);
	new_ptr = malloc(size);
	if (allocated_ptr != NULL && new_ptr != NULL)
	{
		ft_memcpy(new_ptr, allocated_ptr, node_size(node));
		free(allocated_ptr);
	}
	return (new_ptr);
}
