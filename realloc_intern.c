/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_intern.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 14:05:28 by                   #+#    #+#             */
/*   Updated: 2019/06/12 14:05:28 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memutils.h"
#include "malloc.h"
#include "free_node.h"
#include "constants.h"
#include <assert.h>
#include <stdlib.h>

static int	grow_node(struct s_free_node *const node, size_t const size)
{
	int			saved_space;
	int const	original_size = node_size(node);

	saved_space = 0;
	if (!is_last_node(node) && next_node(node)->free)
	{
		saved_space = merge_with_next_nodes(next_node(node));
		if (node_size(node) + node_size(next_node(node)) + sizeof(*node)
			>= size)
			saved_space += merge_with_next_nodes(node);
	}
	return (original_size - (node_size(node) - saved_space));
}

static int	reduce_node(struct s_free_node *const node, size_t const size)
{
	int const	original_size = node_size(node);
	size_t		gained_size;

	if (size <= node_size(node)
			&& node_size_category(node) > size_to_size_category(size))
		carve_node(node, size);
	gained_size = original_size - node_size(node);
	if (gained_size != 0)
		gained_size -= sizeof(*node);
	return (gained_size);
}

static void	adjust_page_size(
		struct s_free_node const *node,
		int const size_diff)
{
	while (!is_last_node(node))
		node = next_node(node);
	get_page_from_first_node(next_node(node))->total_free_size += size_diff;
}

static void	*move_alloc(
		void *old_ptr,
		size_t const new_size,
		int const reallocf)
{
	void *const	new_ptr = malloc(new_size);

	if (new_ptr != NULL)
	{
		ft_memcpy(new_ptr, old_ptr, node_size(
				get_node_from_address(old_ptr)));
		if (!reallocf)
			free(old_ptr);
	}
	if (reallocf)
		free(old_ptr);
	return (new_ptr);
}

void		*realloc_intern(
		void *const allocated_ptr,
		size_t const size,
		int const reallocf)
{
	struct s_free_node *const	node = get_node_from_address(allocated_ptr);
	size_t						size_diff;

	if (allocated_ptr == NULL)
		return (malloc(size));
	else if (!address_is_valid(allocated_ptr))
		return (NULL);
	if (size == 0)
	{
		free(allocated_ptr);
		return (NULL);
	}
	size_diff = reduce_node(node, size);
	if (size_diff == 0)
		size_diff = grow_node(node, size);
	if (size_diff != 0)
		adjust_page_size(node, size_diff);
	assert(malloc_pages_in_good_state());
	return (node_size(node) >= size
			? allocated_ptr : move_alloc(allocated_ptr, size, reallocf));
}
