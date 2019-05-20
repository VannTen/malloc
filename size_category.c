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
	if (size_category == 0)
		return (0);
	return (ALIGNMENT
			- sizeof(struct s_free_node)
			+ (size_category - 1) * ALIGNMENT);
}

size_t	size_to_size_category(size_t size)
{
	size_t static const category_1_size = ALIGNMENT
		- sizeof(struct s_free_node);

	if (size == 0)
		return (0);
	else if (size <= category_1_size)
		return (1);
	else
		return (1 + (size - category_1_size) / ALIGNMENT
				 + ((size - category_1_size) % ALIGNMENT) != 0);
}
