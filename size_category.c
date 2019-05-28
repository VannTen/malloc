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

#include <stddef.h>
#include "constants.h"
#include "max.h"

size_t	size_category_to_size(size_t size_category)
{
	return (ALIGNMENT
			- sizeof(struct s_free_node)
			+ (size_category - 1) * ALIGNMENT);
}

size_t	size_to_size_category(size_t size)
{
	size_t static const cat_1_size = ALIGNMENT - sizeof(struct s_free_node);

	return (1 + (size > cat_1_size ?
				(size - cat_1_size) / ALIGNMENT
				+ (((size - cat_1_size) % ALIGNMENT) != 0)
				: 0));
}

size_t	node_size_category(struct s_free_node const *node)
{
	return (size_to_size_category(node_size(node)
				- sizeof(*node) * !!is_last_node(node)));
}

size_t	page_biggest_free_node_category(struct s_alloc_zone const *page)
{
	size_t						category;
	struct s_free_node const	*node;

	category = 0;
	node = get_first_node(page);
	while (1)
	{
		category = size_t_max(category, node_size_category(node));
		if (is_last_node(node))
			break ;
		node = next_node(node);
	}
	return (category);
}
