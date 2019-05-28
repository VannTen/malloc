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

size_t	ft_strlen_gen(const char *str, const char end_of_line)
{
	size_t	length;

	length = 0;
	while (str[length] != end_of_line)
		length++;
	return (length);
}

size_t	ft_strlen(const char *str)
{
	return (ft_strlen_gen(str, '\0'));
}

size_t	ft_strnlen_gen(const char *str, size_t size, const char end_of_line)
{
	size_t length;

	length = 0;
	while (str[length] != end_of_line && length < size)
		length++;
	return (length);
}

size_t	ft_strnlen(const char *str, size_t size)
{
	return (ft_strnlen_gen(str, size, '\0'));
}
