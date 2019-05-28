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
#include <stdio.h>
#define SIZE_TEST 50000
#define MAX_ALLOC 200

int	main(void)
{
	void	*address[SIZE_TEST];
	size_t	index;
	size_t	total;
	size_t	alloc_size;

	index = (total = 0);
	while (index < SIZE_TEST)
	{
		alloc_size = rand() % MAX_ALLOC;
		total += alloc_size;
		address[index] = malloc(alloc_size);
		printf("Allocation index : %zu, allocation size : %zu, "
				"total allocation size : %zu, allocation result %p\n",
				index, alloc_size, total, address[index]);
		if (address[index] == NULL)
			return (1);
		index++;
	}
	index = 0;
	while (index < SIZE_TEST)
	{
		free(address[index]);
		if (address[index] == NULL)
			return (1);
		index++;
	}
	return (0);
}
