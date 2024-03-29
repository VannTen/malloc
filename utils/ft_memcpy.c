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
** Copy n bytes from src memory to dst memory
** Behavior is undefined if src and dst overlap
*/

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	size_t		index;
	const char	*mem_src;
	char		*mem_dst;

	mem_src = (const char*)src;
	mem_dst = (char*)dst;
	index = 0;
	while (index < len)
	{
		mem_dst[index] = mem_src[index];
		index++;
	}
	return (dst);
}
