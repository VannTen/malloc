/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_node_get_addresses.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 16:45:02 by                   #+#    #+#             */
/*   Updated: 2019/05/28 16:45:02 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_node.h"
#include <stddef.h>

void const	*get_public_address(struct s_free_node const *const node)
{
	return (node + (node != NULL));
}

void const	*end_of_node(struct s_free_node const *const node)
{
	return (((char const *)get_public_address(node)) + node_size(node));
}
