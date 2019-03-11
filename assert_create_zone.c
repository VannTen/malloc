/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert_create_zone.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 16:25:53 by                   #+#    #+#             */
/*   Updated: 2019/03/11 16:25:53 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alloc_zone.h"
#include "free_node.h"
#include "bool.h"

t_bool	assert_create_zone(struct s_alloc_zone const *zone)
{
	struct s_free_node	const * const first_node =
		(struct s_free_node const * const)((char*)zone +  round_up_to_multiple(
			sizeof *zone + sizeof *first_node,
			LOG_2_ALIGN) - sizeof *first_node);

	return (first_node->next == first_node && first_node->free);
}
