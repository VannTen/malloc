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

	zone = create_zone(4096);
	printf("%p\n", (void*)zone);
	assert(assert_create_zone(zone));
	//munmap(zone, 4096);

	get_first_fit(zone, 13);
	return (0);
}
