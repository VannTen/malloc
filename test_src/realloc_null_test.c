/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_null_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 11:14:20 by                   #+#    #+#             */
/*   Updated: 2019/06/07 11:14:20 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#define SIZE_TEST 50000

int	main(void)
{
	int		*address[SIZE_TEST];
	size_t	index;

	index = 0;
	while (index < SIZE_TEST)
	{
		address[index] = NULL;
		index++;
	}
	index = 0;
	while (index < SIZE_TEST)
	{
		address[index] = realloc(address[index], sizeof(**address));
		*(address[index]) = 333;
		index++;
	}
	index = 0;
	while (index < SIZE_TEST)
	{
		free(address[index]);
		index++;
	}
	return (0);
}
