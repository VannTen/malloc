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
#include <assert.h>

int	main( void )
{
	struct s_alloc_zone * zone = create_zone(4096);
	struct s_free_node const * ptr[5];

	assert(nb_node(zone) == 1);
	assert(nb_free_node(zone) == 1);
	for (size_t i = 0;i < 5;i++)
	{
		ptr[i] = get_first_fit(zone, 56);
	}
	assert(nb_node(zone) == 6);
	assert(nb_free_node(zone) == 1);
	for (size_t i = 0;i < 5;i++)
	{
		free_node((void*)get_public_address(ptr[i]));
		assert(nb_free_node(zone) == (i < 5 ? i + 2 : 1));
		assert(nb_node(zone) == (i < 5 ? 6 : 1));
	}

	return (0);
}
