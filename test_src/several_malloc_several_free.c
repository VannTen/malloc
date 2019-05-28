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
