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

#include "itoa_tools.h"
#include <stddef.h>
#include <stdint.h>

size_t	itoa_len_signed(intmax_t number, int base)
{
	size_t	size;

	if (number == 0)
		return (1);
	size = 0;
	while (number != 0)
	{
		number = number / base;
		size++;
	}
	return (size);
}

size_t	itoa_len_unsigned(uintmax_t number, unsigned int base)
{
	size_t	size;

	if (number == 0)
		return (1);
	size = 0;
	while (number != 0)
	{
		number = number / base;
		size++;
	}
	return (size);
}

void	itoa_write_signed(char *str, intmax_t number, const unsigned int base,
		const char *base_digits)
{
	int	digit;

	digit = number % base;
	if (number < 0)
		digit = -digit;
	*str = base_digits[digit];
	if (number / base != 0)
		itoa_write_signed(str - 1, number / base, base, base_digits);
}

void	itoa_write_unsigned(char *str, uintmax_t number,
		const unsigned int base, const char *base_digits)
{
	int digit;

	digit = number % base;
	*str = base_digits[digit];
	if (number / base != 0)
		itoa_write_unsigned(str - 1, number / base, base, base_digits);
}
