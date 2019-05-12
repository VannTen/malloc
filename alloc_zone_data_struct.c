/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_zone_data_struct.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 16:33:50 by                   #+#    #+#             */
/*   Updated: 2019/05/12 16:33:50 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alloc_zone.h"
#include <stddef.h>

struct s_alloc_zone const *page_from_list_node(struct s_list const *node)
{
	if (node == NULL)
		return (NULL);
	return ((void const*)(
			((char const*)node) - offsetof(struct s_alloc_zone, list)));
}
