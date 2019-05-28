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

#include "rb_tree_delete_nephew_cases.h"
#include "rb_tree.h"
#include <assert.h>

static int			post_red_sibling(struct s_rbtree **const tree, int side)
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

static void			red_sibling(struct s_rbtree **tree, int side)
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
		struct s_rbtree **const tree,
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
