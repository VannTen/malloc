/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 14:25:31 by                   #+#    #+#             */
/*   Updated: 2019/03/11 14:25:31 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alloc_zone.h"
#include <stdio.h>
#include <sys/mman.h>
#include <assert.h>

struct s_alloc_zone	*create_zone(size_t	size);

int main( void )
{
	struct s_alloc_zone * zone;
	void const			* ptr[10];

	zone = create_zone(4096);
	assert(assert_create_zone(zone));
	//munmap(zone, 4096);


	for (size_t i = 0; i < 10; i++)
	{
		ptr[i] = get_first_fit(zone, 13);
		printf("%p\n", ptr[i]);
		assert(nb_node(zone) == 2 + i);
	}
	for (size_t i = 0; i < 10; i++)
	{
		free_node((void*)ptr[i]);
		assert(nb_free_node(zone) == 2 + i);
	}
	printf("%zu\n", nb_node(zone));
	printf("%zu\n", nb_free_node(zone));

	ptr[0] = get_first_fit(zone, 13);
	ptr[1] = get_first_fit(zone, 13);
	free_defrag((void*)ptr[1]);
	printf("%zu\n", nb_node(zone));
	printf("%zu\n", nb_free_node(zone));
	return (0);
}
