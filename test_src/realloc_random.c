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

#include <stdlib.h>
#include "memutils.h"
#define SIZE_TEST 50000
#define MAX_ALLOC_SIZE 10000
#define FILL_BYTE '$'

static void	alloc_ints(void **address)
{
	size_t	index;
	size_t	alloc_size;

	index = 0;
	while (index < SIZE_TEST)
	{
		alloc_size = rand() % MAX_ALLOC_SIZE;
		address[index] = malloc(alloc_size);
		ft_memset(address[index], FILL_BYTE, alloc_size);
		index++;
	}
}

int	main(void)
{
	void	*address[SIZE_TEST];
	size_t	index;
	size_t	alloc_size;

	alloc_ints(address);
	index = 1;
	while (index < SIZE_TEST)
	{
		free(address[index]);
		address[index] = NULL;
		index += 2;
	}
	index = 0;
	while (index < SIZE_TEST)
	{
		alloc_size = rand() % MAX_ALLOC_SIZE;
		address[index] = realloc(address[index], alloc_size);
		ft_memset(address[index], FILL_BYTE, alloc_size);
		index++;
		index += 2;
	}
	return (0);
}
