/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_zone_get_space.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 16:37:24 by                   #+#    #+#             */
/*   Updated: 2019/06/08 16:37:24 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alloc_zone.h"
#include "constants.h"

static size_t	init_size(size_t cat_max)
{
	return (page_size(cat_max) - offset_zone_start_first_address());
}

static int	test_tiny(void)
{
	struct s_alloc_zone	*const	zone = create_zone(tiny_page_size());
	size_t const				expected_initial_size = init_page(TINY_MAX);
	size_t						node_taken;
	size_t const				node_to_take = 10;

	if (alloc_zone_free_space(zone) != expected_initial_size)
		return (1);
	node_taken = 0;
	while (node_taken < node_to_take)
	{
		get_first_fit(zone, tiny_size_limit());
		node_taken++;
	}
	return (alloc_zone_free_space(zone)
			== expected_initial_size
			- node_taken * (tiny_size_limit() + sizeof(struct s_free_node)));
}

static int	test_small(void)
{
	struct s_alloc_zone	*const	zone = create_zone(small_page_size());
	size_t const				expected_initial_size = init_size(SMALL_MAX);
	size_t						node_taken;
	size_t const				node_to_take = 10;

	if (alloc_zone_free_space(zone) != expected_initial_size)
		return (1);
	node_taken = 0;
	while (node_taken < node_to_take)
	{
		get_first_fit(zone, small_size_limit());
		node_taken++;
	}
	return (alloc_zone_free_space(zone)
			== expected_initial_size
			- node_taken * (small_size_limit() + sizeof(struct s_free_node)));
}

int			main(void)
{
	return (!(test_tiny() && test_small()));
}
