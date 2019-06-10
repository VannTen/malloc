/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_zone_sanity_checks.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 15:57:23 by                   #+#    #+#             */
/*   Updated: 2019/06/10 15:57:23 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alloc_zone.h"

int	bad_page(struct s_alloc_zone const *const page)
{
	return (alloc_zone_free_space(page) != page->total_free_size);
}
