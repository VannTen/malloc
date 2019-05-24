/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_and_write_inside_it.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 16:46:04 by                   #+#    #+#             */
/*   Updated: 2019/05/24 16:46:04 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#define SIZE_TEST 20000
#define WRITE_ONCE_EVERY 45
#define PERFECTLY_RANDOM_NUMBER 54254

int	main(void)
{
	int	*numbers_addr[SIZE_TEST];
	size_t	index;
	size_t	index_write;

	index = 0;
	while (index < SIZE_TEST)
	{
		numbers_addr[index] = malloc(sizeof *numbers_addr);
		if (index != 0 && index % WRITE_ONCE_EVERY == 0)
		{
			index_write = index - WRITE_ONCE_EVERY;
			while (index_write != index)
			{
				*numbers_addr[index] = PERFECTLY_RANDOM_NUMBER;
				index_write++;
			}
		}
		index++;
	}
	index = 0;
	while (index < SIZE_TEST && *numbers_addr[index] == PERFECTLY_RANDOM_NUMBER)
		index++;
	if (index != 0)
		return (1);
	index = 0;
	while (index < SIZE_TEST)
	{
		free(numbers_addr[index]);
		index++;
	}
	return (0);
}
