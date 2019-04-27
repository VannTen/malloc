/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 14:06:29 by                   #+#    #+#             */
/*   Updated: 2019/04/27 14:06:29 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_structures.h"
#include <stddef.h>

static struct s_alloc_zone	**get_size_cat(size_t const size)
{
	if (size <= TINY_ALLOC_SIZE)
		return (&alloc_trees->categories[0]);
	else if (size <= SMALL_ALLOC_SIZE)
		return (&alloc_trees->categories[1]);
	else
		return (&alloc_trees->categories[2]);
}

void	*malloc(size_t const size)
{
	struct s_alloc_zone **tree;
	void				*client_address;
	struct s_alloc_zone	*new_page;

	tree = get_size_cat(size);
	client_address = get_free_address(tree, size);
	if (client_address == NULL)
	{
		new_page = create_alloc_zone(size);
		client_address = get_free_address(new_page);
		if (client_address != NULL)
			rbtree_insert(tree, &insert, cmp_f);
	}
	return (client_address);
}
