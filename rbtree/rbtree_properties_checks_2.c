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

#include "rb_tree.h"

static int	reds_have_black_childs(struct s_rbtree const * const tree)
{
	if (tree == NULL)
		return (1);
	else
		return (((color(tree) == BLACK)
					|| (color(tree->children[LEFT]) == BLACK && BLACK == color(tree->children[RIGHT])))
				&& reds_have_black_childs(tree->children[LEFT])
				&& reds_have_black_childs(tree->children[RIGHT]));
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
