/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree_properties_checks_2.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 12:27:03 by                   #+#    #+#             */
/*   Updated: 2019/04/10 12:27:03 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rb_tree.h"

static int	reds_have_black_childs(struct s_rbtree const * const tree)
{
	if (tree == NULL)
		return (1);
	else
		return (((color(tree) == BLACK)
					|| (color(tree->left) == BLACK && BLACK == color(tree->right)))
				&& reds_have_black_childs(tree->left)
				&& reds_have_black_childs(tree->right));
}

static int	root_is_black(struct s_rbtree const * const tree)
{
	return (color(tree) == BLACK);
}

int	is_valid_rb_tree(struct s_rbtree const * const tree)
{
	return (reds_have_black_childs(tree)
			&& root_is_black(tree)
			&& (tree == NULL || black_depth(tree) != 0));
}
