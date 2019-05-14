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

int	main(void)
{
	void	*addresses[500];
	size_t	index;

	index = 1;
	while (index < 500)
	{
		addresses[index - 1] = malloc(1);
		index++;
	}
	while (index != 0)
	{
		free(addresses[index - 1]);
		index--;
	}
	return (0);
}
