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

#include "alloc_zone.h"
#include <stdint.h>

int					alloc_zone_cmp(
		void const *ref,
		void const *compared)
{
	if ((uintptr_t)ref > (uintptr_t)compared)
		return (1);
	else if ((uintptr_t)ref < (uintptr_t)compared)
		return (-1);
	else
		return (0);
}
