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

#include <unistd.h>
#include <stdlib.h>
#define R 10000

int	main(void)
{
	uint32_t	b;
	void		*ptr;

	b = arc4random_uniform(R);
	while (b-- > 0)
	{
		ptr = malloc((size_t)arc4random_uniform(R));
		if (arc4random_uniform(2))
			free(ptr);
		else if (arc4random_uniform(2))
			ptr = realloc(ptr, (size_t)arc4random_uniform(R));
	}
	return (0);
}
