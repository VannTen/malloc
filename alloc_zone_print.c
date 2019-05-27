/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_zone_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 11:14:00 by                   #+#    #+#             */
/*   Updated: 2019/05/27 11:14:00 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alloc_zone.h"
#include "constants.h"
#include "free_node.h"
#include <assert.h>

char const *select_type_string(struct s_alloc_zone const *zone)
{
	char const					*type_string;

	if (zone->biggest_free_size == LARGE_MAGIC_NUMBER)
		type_string = "LARGE";
	else if (zone->size == tiny_page_size())
		type_string = "TINY";
	else
		type_string = "SMALL";
	return (type_string);
}

int	alloc_zone_print(struct s_alloc_zone const *zone)
{
	char const * const			 type_string  = select_type_string(zone);
	size_t						index;
	struct s_free_node const	*node;
	int							write_ret;

	assert(zone != NULL);
	index = ft_strlen(type_string);
	node = get_first_node(zone);
	write_ret = 0;
	while (1)
	{
		if (!node->free)
		{
			write_ret = ft_printf("%p - %p : %zu octets\n",
						get_public_address(node), end_of_node(node), node_size(node));
			if (write_ret < 0)
				return (write_ret);
		}
		if (is_last_node(node))
			break ;
		node = next_node(node);
	}
	return (write_ret);
}
