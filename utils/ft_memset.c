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

#include <stddef.h>

/*
** Set len bytes to c at the adress pointed
*/

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			index;
	unsigned char	content;
	char			*memory;

	content = (unsigned char)c;
	memory = (char*)b;
	index = 0;
	while (index < len)
	{
		memory[index] = content;
		index++;
	}
	return (b);
}
