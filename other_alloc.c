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

#include "memutils.h"
#include "intern_alloc_helpers.h"
#include <stdint.h>
#include <stdlib.h>

void		*realloc(void *const allocated_ptr, size_t const new_size)
{
	return (realloc_intern(allocated_ptr, new_size, 0));
}

void		*reallocf(void *const allocated_ptr, size_t const new_size)
{
	return (realloc_intern(allocated_ptr, new_size, 1));
}

void		*calloc(size_t const count, size_t const size)
{
	void	*ptr;

	ptr = NULL;
	if (count != 0 && SIZE_MAX / count > size)
	{
		ptr = malloc(count * size);
		if (ptr != NULL)
			ft_memset(ptr, 0x0, size * count);
	}
	return (ptr);
}
