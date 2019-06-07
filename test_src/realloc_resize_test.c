/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_resize_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 11:24:54 by                   #+#    #+#             */
/*   Updated: 2019/06/07 11:24:54 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#define SIZE_TEST 50000

static void	alloc_ints(void **address)
{
	size_t	index;

	index = 0;
	while (index < SIZE_TEST)
	{
		address[index] = malloc(sizeof(int));
		*((int*)address[index]) = 444444;
		index++;
	}
}

int	main(void)
{
	void	*address[SIZE_TEST];
	size_t	index;
	int		*addr;

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
		address[index] = realloc(address[index], sizeof(int) * 2);
		addr = address[index];
		addr[0] = 4444444;
		addr[1] = 22222222;
		index += 2;
	}
	return (0);
}
