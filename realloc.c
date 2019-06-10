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
#include "constants.h"
#include "memutils.h"
#include "malloc.h"
#include <stdlib.h>
#include <assert.h>

static int	grow_node(struct s_free_node *const node, size_t const size)
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

static int	reduce_node(struct s_free_node *const node, size_t const size)
{
	if (size <= node_size(node))
	{
		if (node_size_category(node) > size_to_size_category(size))
			carve_node(node, size);
		return (1);
	}
	return (0);
}

void		*realloc(void *const allocated_ptr, size_t const size)
{
	struct s_free_node *const	node = get_node_from_address(allocated_ptr);
	void						*new_ptr;

	if (size == 0)
	{
		free(allocated_ptr);
		return (NULL);
	}
	else if (node != NULL && (reduce_node(node, size) || grow_node(node, size)))
		return (allocated_ptr);
	new_ptr = malloc(size);
	if (allocated_ptr != NULL && new_ptr != NULL)
	{
		ft_memcpy(new_ptr, allocated_ptr, node_size(node));
		free(allocated_ptr);
	}
	assert(malloc_pages_in_good_state());
	return (new_ptr);
}

void		*reallocf(void *const allocated_ptr, size_t const size)
{
	struct s_free_node *const	node = get_node_from_address(allocated_ptr);
	void						*new_ptr;

	if (size == 0)
	{
		free(allocated_ptr);
		return (NULL);
	}
	else if (node != NULL && (reduce_node(node, size) || grow_node(node, size)))
		return (allocated_ptr);
	new_ptr = malloc(size);
	if (allocated_ptr != NULL && new_ptr != NULL)
		ft_memcpy(new_ptr, allocated_ptr, node_size(node));
	free(allocated_ptr);
	assert(malloc_pages_in_good_state());
	return (new_ptr);
}

void		*calloc(size_t const count, size_t const size)
{
	void	*ptr;

	ptr = NULL;
	if (SIZE_MAX / count > size)
	{
		ptr = malloc(count * size);
		if (ptr != NULL)
			ft_memset(ptr, 0x0, size);
	}
	return (ptr);
}
