/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree_metadata.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 13:12:42 by                   #+#    #+#             */
/*   Updated: 2019/04/26 13:12:42 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rb_tree.h"
#include <stddef.h>

size_t	rbtree_node_count(struct s_rbtree const * const tree)
{
	if (tree == NULL)
		return (0);
	else
		return (1
				+ rbtree_node_count(tree->children[LEFT])
				+ rbtree_node_count(tree->children[RIGHT]));
}
