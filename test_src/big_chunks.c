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
#define TEST_SIZE 100000
#define CHUNK_SIZE 2000

int	main(void)
{
	void	*address[TEST_SIZE];
	size_t	index;

	index = 0;
	while (index < TEST_SIZE)
	{
		address[index] = malloc(CHUNK_SIZE);
		index++;
	}
	while (index != 0)
	{
		index--;
		free(address[index]);
		if (address[index] == NULL)
			break ;
	}
	return (index);
}
