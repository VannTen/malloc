/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   several_size_malloc_and_free.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 11:08:05 by                   #+#    #+#             */
/*   Updated: 2019/05/20 11:08:05 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#define SIZE_TEST 500
#define MAX_ALLOC 200

int	main(void)
{
	void	*address[SIZE_TEST];
	size_t	index;
	size_t	alloc_size;

	index = 0;
	while (index < SIZE_TEST)
	{
		alloc_size = rand() % MAX_ALLOC;
		printf("%zu\n", alloc_size);
		address[index] = malloc(alloc_size);
		index++;
	}
	index = 0;
	while (index < SIZE_TEST)
	{
		free(address[index]);
		index++;
		if (address[index] == NULL)
			return (1);
	}
	return (0);
}
