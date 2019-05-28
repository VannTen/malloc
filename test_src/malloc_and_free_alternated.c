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
#define MAX_ALLOC_SIZE 3800
#define STEP_BACK 45

void	free_address(void **address)
{
	size_t	index;

	index = 0;
	while (index < SIZE_TEST)
	{
		free(address[index]);
		index++;
	}
}

int		main(void)
{
	void	*addresses[SIZE_TEST];
	size_t	index;

	index = 0;
	while (index < SIZE_TEST)
	{
		addresses[index] = NULL;
		index++;
	}
	index = 0;
	while (index < SIZE_TEST)
	{
		if (addresses[index] == NULL)
			addresses[index] = malloc(rand() % MAX_ALLOC_SIZE);
		else
		{
			free(addresses[index]);
			addresses[index] = NULL;
		}
		if (index > STEP_BACK && rand() % (STEP_BACK * 2) == 0)
			index -= rand() % STEP_BACK;
		index++;
	}
	free_address(addresses);
	return (0);
}
