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
