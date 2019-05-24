/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_and_free_alternated.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 17:04:04 by                   #+#    #+#             */
/*   Updated: 2019/05/24 17:04:04 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#define SIZE_TEST 50000
#define MAX_ALLOC_SIZE 3800
#define STEP_BACK 45

int	main(void)
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
	index = 0;
	while (index < SIZE_TEST)
	{
		free(addresses[index]);
		index++;
	}
	return (0);
}
