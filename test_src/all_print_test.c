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

#include "malloc.h"
#include <stdlib.h>
#define SIZE_TEST 300
#define MAX_SIZE_ALLOC 600

int	main(void)
{
	void	*ptr[SIZE_TEST];
	size_t	index;

	index = 0;
	while (index < SIZE_TEST)
	{
		ptr[index] = malloc(rand() % MAX_SIZE_ALLOC);
		index++;
	}
	show_alloc_mem();
	index = 0;
	while (index < SIZE_TEST)
	{
		free(ptr[index]);
		index++;
	}
	show_alloc_mem();
}
