/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_with_free_spaces.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 16:07:26 by                   #+#    #+#             */
/*   Updated: 2019/06/08 16:07:26 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#define SIZE_TEST 50000

static void	free_addr(long **tab, size_t const size)
{
	size_t	index;

	index = 0;
	while (index < size)
	{
		free(tab[index]);
		index++;
	}
}

int			main(void)
{
	long	*address[SIZE_TEST];
	size_t	index;

	index = 0;
	while (index < SIZE_TEST)
	{
		address[index] = malloc(sizeof(long));
		*(address[index]) = LONG_MAX - 50000;
		index++;
	}
	index = 1;
	while (index < SIZE_TEST)
	{
		free(address[index]);
		index += 2;
	}
	index = 1;
	while (index < SIZE_TEST)
	{
		address[index] = malloc(sizeof(long));
		*(address[index]) = LONG_MAX - (long)INT_MAX * 56;
		index += 2;
	}
	free_addr(address, SIZE_TEST);
	return (0);
}
