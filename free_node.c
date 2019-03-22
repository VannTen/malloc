/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:31:53 by                   #+#    #+#             */
/*   Updated: 2019/03/14 17:31:53 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_node.h"
#include "bool.h"
#include <assert.h>

void const	*publish_address(struct s_free_node * node)
{
	assert(node->free);
	node->free = FALSE;
	return (get_public_address(node));
}

void		free_node(void *ptr)
{
	struct s_free_node * const node = (struct s_free_node *)ptr - 1;

	node->free = TRUE;
}
