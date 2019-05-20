/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_chunks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 15:20:37 by                   #+#    #+#             */
/*   Updated: 2019/05/17 15:20:37 by                  ###   ########.fr       */
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
