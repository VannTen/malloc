/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_debug.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 11:23:53 by                   #+#    #+#             */
/*   Updated: 2019/05/29 11:23:53 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_structures.h"
#include "malloc_intern_debug.h"
#include <stddef.h>

int	large_in_bad_places(struct s_alloc_categorie const *const malloc_zone)
{
	size_t	index;

	index = 0;
	while (index < SMALL_MAX
			&& (malloc_zone->block_by_size[index] == NULL
				|| malloc_zone->block_by_size[index]->biggest_free_size
				!= LARGE_MAGIC_NUMBER))
		index++;
	return (index != SMALL_MAX);
}
