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
	short	size;

	if (size_category == 0)
		return (0);
	size = ALIGNMENT - sizeof (struct s_free_node);
	size_category--;
	size = size + size_category * ALIGNMENT;
	return (size);
}

size_t	size_to_size_category(size_t size)
{
	size_t	category;

	if (size == 0)
		return (0);
	category = 1;
	size -= ALIGNMENT - sizeof(struct s_free_node);
	category =+ size / ALIGNMENT;
	return (category);
}
