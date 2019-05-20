/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_category.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 18:31:10 by                   #+#    #+#             */
/*   Updated: 2019/05/16 18:31:10 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "constants.h"

size_t	size_category_to_size(size_t size_category)
{
	return (ALIGNMENT
			- sizeof(struct s_free_node)
			+ (size_category) * ALIGNMENT);
}

size_t	size_to_size_category(size_t size)
{
	size_t static const category_1_size = ALIGNMENT
		- sizeof(struct s_free_node);

	if (size <= category_1_size)
		return (0);
	else
		return ((size - category_1_size) / ALIGNMENT
				 + (((size - category_1_size) % ALIGNMENT) != 0));
}

size_t	node_size_category(struct s_free_node const *node)
{
	return (size_to_size_category(node_size(node)));
}
