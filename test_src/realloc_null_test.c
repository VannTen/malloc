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
