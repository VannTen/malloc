/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_first_fit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 13:30:59 by                   #+#    #+#             */
/*   Updated: 2019/02/25 13:30:59 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alloc_zone.h"
#include "free_node.h"
#include "bool.h"
#include <stddef.h>


static t_bool	is_last_node(struct s_free_node const * node)
{
	return (node->next <= node);
}
t_bool	node_fits(struct s_free_node *node, size_t size)
{
	if (node_size(node) < size)
		return (FALSE);
	else if (node_size(node) > size)
		carve_new_node(node, size);
	return (TRUE);
}


void	*get_first_fit(struct s_alloc_zone *zone, size_t size_required)
{
	struct s_free_node *	node;
	t_bool					found_fitting_node;

	node = get_first_node(zone);
	found_fitting_node = FALSE;
	while (!node_fits(node, size_required))
	{
		node = node->next;
		if (is_last_node(node))
			break ;
	}
	if (node_fits(node, size_required))
	{
		carve_node(node, size_required);
		found_fitting_node = TRUE;
	}
	return (found_fitting_node ? get_public_address(node) : NULL);
}
