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
