/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_zone_get_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 16:59:12 by                   #+#    #+#             */
/*   Updated: 2019/05/28 16:59:12 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alloc_zone.h"
#include "constants.h"
#include <assert.h>

void			*end_of_zone(struct s_alloc_zone const *const start_of_zone)
{
	return ((char*)start_of_zone + start_of_zone->size);
}

size_t			page_size_category(struct s_alloc_zone const *page)
{
	assert(page->biggest_free_size != LARGE_MAGIC_NUMBER);
	return (page->biggest_free_size);
}
