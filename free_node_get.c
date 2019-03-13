/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_node_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 13:54:00 by                   #+#    #+#             */
/*   Updated: 2019/03/13 13:54:00 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_node.h"

void	*get_public_address(struct s_free_node const * const node)
{
	return (node + 1);
}

size_t	node_size(struct s_free_node const * const node)
{
	if (is_last_node(node))
		return (0);
		// TODO
	else
		return ((char*)node->next - (char*)node);
}

