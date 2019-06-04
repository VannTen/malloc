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
#include <stdio.h>

static int	small_size(void)
{
	struct s_alloc_zone *const	zone = create_zone(small_page_size());
	size_t						index;

	index = 0;
	while (get_first_fit(zone, small_size_limit()) != NULL)
		index++;
	printf("zone small contains %zu allocations of maximal size (%zu octets).\n"
			, index, small_size_limit());
	return (index >= 100);
}

static int	tiny_size(void)
{
	struct s_alloc_zone *const	zone = create_zone(tiny_page_size());
	size_t						index;

	index = 0;
	while (get_first_fit(zone, tiny_size_limit()) != NULL)
		index++;
	printf("zone tiny contains %zu allocations of maximal size (%zu octets).\n"
			, index, tiny_size_limit());
	return (index >= 100);
}

int			main(void)
{
	return (!(tiny_size() && small_size()));
}
