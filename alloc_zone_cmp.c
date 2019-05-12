/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_zone_cmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 16:56:59 by                   #+#    #+#             */
/*   Updated: 2019/05/12 16:56:59 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alloc_zone.h"
#include <stdint.h>

int					alloc_zone_cmp(
		struct s_alloc_zone const *ref,
		struct s_alloc_zone const *compared)
{
	if ((uintptr_t)compared < (uintptr_t)ref)
		return (-1);
	else if ((uintptr_t)compared > (uintptr_t)ref)
		return (1);
	else
		return (0);
}
