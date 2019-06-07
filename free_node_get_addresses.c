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

#include "free_node.h"
#include <stddef.h>

void const			*get_public_address(struct s_free_node const *const node)
{
	return (node + (node != NULL));
}

struct s_free_node	*get_node_from_address(void *const address)
{
	return (((struct s_free_node *)address) - (address != NULL));
}

void const			*end_of_node(struct s_free_node const *const node)
{
	return (((char const *)get_public_address(node)) + node_size(node));
}
