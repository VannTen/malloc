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

#include "alloc_zone.h"
#include "constants.h"
#include <assert.h>

void	*end_of_zone(struct s_alloc_zone const *const start_of_zone)
{
	return ((char*)start_of_zone + start_of_zone->size);
}

int		is_large(struct s_alloc_zone const *const page)
{
	return (is_last_node(get_first_node(page)));
}

int		is_tiny(struct s_alloc_zone const *const page)
{
	return (page->size == tiny_page_size()
			&& (!is_last_node(get_first_node(page))
				|| get_first_node(page)->free));
}

int		is_small(struct s_alloc_zone const *const page)
{
	return (page->size == small_page_size()
			&& (!is_last_node(get_first_node(page))
				|| get_first_node(page)->free));
}
