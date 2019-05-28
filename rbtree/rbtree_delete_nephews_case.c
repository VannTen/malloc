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
#include "rb_tree_delete_nephew_cases.h"

static struct s_rbtree	*grand_child(struct s_rbtree *tree,
		int const child_side, int const grand_child_side)
{
	return (tree->children[child_side]->children[grand_child_side]);
}

void					parent_sibling_nephews_black(
		struct s_rbtree **tree,
		int side)
{
	(*tree)->children[!side]->color = RED;
}

void					parent_red_sib_neph_black(
		struct s_rbtree **tree, int side)
{
	(*tree)->color = BLACK;
	(*tree)->children[!side]->color = RED;
}

void					outer_red_nephew(struct s_rbtree **tree, int side)
{
	enum e_color const		tmp = (*tree)->color;
	struct s_rbtree *const	outer_nephew = grand_child(*tree, !side, !side);

	(*tree)->color = BLACK;
	(side ? right_rotate : left_rotate)(tree);
	(*tree)->color = tmp;
	outer_nephew->color = BLACK;
}

void					inner_red_nephew(struct s_rbtree **tree, int side)
{
	struct s_rbtree **const	sibling = &(*tree)->children[!side];
	struct s_rbtree *const	inner_nephew = (*sibling)->children[side];

	(side ? left_rotate : right_rotate)(sibling);
	(*sibling)->color = RED;
	inner_nephew->color = BLACK;
	outer_red_nephew(tree, side);
}
