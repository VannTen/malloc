/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   several_malloc_several_free.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 16:51:02 by                   #+#    #+#             */
/*   Updated: 2019/05/14 16:51:02 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#define NB_ADDRESS 4000

int	main(void)
{
	void	*addresses[NB_ADDRESS];
	size_t	index;

	index = 0;
	while (index < NB_ADDRESS)
	{
		addresses[index] = malloc(1);
		index++;
	}
	while (index != 0)
	{
		index--;
		free(addresses[index]);
	}
	return (0);
}
