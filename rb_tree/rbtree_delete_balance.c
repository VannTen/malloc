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
#include <assert.h>

static void			parent_sibling_nephews_black(struct s_rbtree ** tree, int side)
{
	(*tree)->children[!side]->color = RED;
}

static void			parent_red_sib_neph_black(struct s_rbtree ** tree, int side)
{
	(*tree)->color = BLACK;
	(*tree)->children[!side]->color = RED;
}

static void			outer_red_nephew(struct s_rbtree ** tree, int side)
{
	enum e_color const	tmp = (*tree)->color;

	(side ? right_rotate : left_rotate)(tree);
	(*tree)->color = tmp;
	(*tree)->children[side]->color = BLACK;
}

static void			inner_red_nephew(struct s_rbtree ** tree, int side)
{
	struct s_rbtree ** const	sibling = &(*tree)->children[!side];
	struct s_rbtree * const		inner_nephew = (*sibling)->children[side];

	(side ? left_rotate : right_rotate)(sibling);
	(*sibling)->color = RED;
	inner_nephew->color = BLACK;
	outer_red_nephew(tree, side);
}

static int			post_red_sibling(struct s_rbtree ** const tree, int side)
{
	int done_something;

	done_something = 0 == 0;
	if (color((*tree)->children[!side]->children[!side]) == RED)
		outer_red_nephew(tree, side);
	else if (color((*tree)->children[!side]->children[side]) == RED)
		inner_red_nephew(tree, side);
	else if (color(*tree) == RED)
		parent_red_sib_neph_black(tree, side);
	else
		done_something = !done_something;
	return (done_something);
}

static void			red_sibling(struct s_rbtree ** tree, int side)
{
	int done;

	(*tree)->color = RED;
	(*tree)->children[!side]->color = BLACK;
	(side ? right_rotate : left_rotate)(tree);
	done = post_red_sibling(
			&(*tree)->children[side], side);
	assert(done);
}

enum e_tree_state	balance_subtree(
		struct s_rbtree ** const tree,
		int const	side,
		enum e_tree_state subtree_state)
{
	if (subtree_state == TREE_HAS_ONE_BLACK_LESS && *tree != NULL)
	{
		subtree_state = GOOD;
		if (color((*tree)->children[!side]) == RED)
			red_sibling(tree, side);
		else if (post_red_sibling(tree, side))
			;
		else
		{
			parent_sibling_nephews_black(tree, side);
			subtree_state = TREE_HAS_ONE_BLACK_LESS;
		}
	}
	return (subtree_state);
}
