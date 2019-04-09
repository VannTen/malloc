/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree_delete_balance.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:29:01 by                   #+#    #+#             */
/*   Updated: 2019/04/08 17:29:01 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rb_tree.h"


static void			red_sibling(struct s_rbtree ** tree, int side)
{
	(*tree)->color = RED;
	sibling->color = BLACK;
	rotate(tree, sibling);
	balance_subtree(tree, ...);
}

static void			parent_sibling_nephews_black(struct s_rbtree ** tree, int side)
{
	sibling->color = RED;
	return (TREE_HAS_ONE_BLACK_LESS);
}

static void			parent_red_sib_neph_black(struct s_rbtree ** tree, int side)
{
	(*tree)->color = BLACK;
	sibling->color = RED;
}

static void			inner_red_nephew(struct s_rbtree ** tree, int side)
{
	rotate(sibling, inner_nephew);
	sibling->color = RED;
	inner_nephew->color = BLACK;
	outer_red_nephew(tree, side);
}

static void			outer_red_nephew(struct s_rbtree ** tree, int side)
{
	enum e_color const	tmp = (*tree)->color;

	rotate(*tree, sibling);
	sibling->color = tmp;
	(*tree)->color = BLACK;
}

enum e_remove_ret	balance_subtree(
		struct s_rbtree ** const tree,
// Which child ?
		enum e_remove_ret subtree_state)
{
	if (subtree_state == TREE_HAS_ONE_BLACK_LESS)
	{
		if ((*tree)->other_child->color == RED)
			red_sibling(tree, );
		else if ((*tree)->other_child->outer_child->color == RED)
			outer_red_nephew(tree, );
		else if ((*tree)->other_child->inner_child->color == RED)
			inner_red_nephew(tree, );
		else if ((*tree)->color == BLACK)
			parent_sibling_nephews_black(tree, side);
		else
			parent_red_sib_neph_black(tree, side);
	}
	return (subtree_state);
}
