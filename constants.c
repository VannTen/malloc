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
#include "free_node.h"
#include "constants.h"
#include <stddef.h>

size_t	offset_zone_start_first_address( void )
{
	return (round_up_to_multiple(
				sizeof (struct s_alloc_zone) + sizeof(struct s_free_node),
				ft_pow(2, LOG_2_ALIGN)));
}

size_t	offset_zone_start_first_free_node( void )
{
	return (offset_zone_start_first_address() - sizeof(struct s_free_node));
}

size_t	ft_pow(size_t n, size_t pow)
{
	return (pow == 0 ? 1 : n * ft_pow(n, pow - 1));
}
