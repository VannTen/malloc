/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_pointers_offsets.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 15:19:53 by                   #+#    #+#             */
/*   Updated: 2019/05/10 15:19:53 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"

struct s_alloc_zone const	*get_page_from_first_node(
		struct s_free_node const *first_node)
{
	return ((void const*)((char const*)first_node
			- offset_zone_start_first_free_node()));
}
