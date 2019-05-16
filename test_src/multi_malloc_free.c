/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_malloc_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 13:58:16 by                   #+#    #+#             */
/*   Updated: 2019/05/14 13:58:16 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	size_t	index;
	void	*address;

	index = 0;
	while (index < 100000)
	{
		address = malloc(10);
		if (address == NULL)
		{
			printf("Failed malloc at %zu attempt\n", index);
			return (1);
		}
		free(address);
		index++;
	}
	return (0);
}
