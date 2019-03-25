/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zone_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 11:12:44 by                   #+#    #+#             */
/*   Updated: 2019/03/25 11:12:44 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alloc_zone.h"
#include <stdio.h>


int	main(void)
{
	struct s_alloc_zone * const zone = create_zone(4096);

	while (get_first_fit(zone, 1) != NULL)
		;
	printf("Zone contains %zu allocations of minimal size.\n", nb_node(zone));
	return (0);
}
