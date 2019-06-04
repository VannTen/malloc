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
#include "free_node.h"
#include <assert.h>
#include <stddef.h>

int	main(void)
{
	struct s_alloc_zone			*zone;
	struct s_free_node const	*ptr[5];
	size_t						index;

	zone = create_zone(4096);
	assert(nb_node(zone) == 1);
	assert(nb_free_node(zone) == 1);
	index = 0;
	while (index < 5)
	{
		ptr[index] = get_first_fit(zone, 56);
		index++;
	}
	assert(nb_node(zone) == 6);
	assert(nb_free_node(zone) == 1);
	index = 0;
	while (index < 5)
	{
		free_node((void*)get_public_address(ptr[index]));
		assert(nb_free_node(zone) == (index < 5 ? index + 2 : 1));
		assert(nb_node(zone) == (index < 5 ? 6 : 1));
		index++;
	}
	return (0);
}
