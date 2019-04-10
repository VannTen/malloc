/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 15:24:34 by                   #+#    #+#             */
/*   Updated: 2019/04/01 15:24:34 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rb_tree.h"
#include <stddef.h>

void	rbtree_init_node(struct s_rbtree * const node)
{
	node->left = NULL;
	node->right = NULL;
	node->color = RED;
}