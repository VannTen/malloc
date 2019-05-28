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
#include <assert.h>
#include <stddef.h>

static enum e_tree_state	delete_node(struct s_rbtree **const node, int side)
{
	struct s_rbtree *const	deleted = *node;

	assert(deleted != NULL);
	assert(deleted->children[LEFT] == NULL || deleted->children[RIGHT] == NULL);
	*node = (*node)->children[side];
	if (color(deleted->children[side]) == RED)
		deleted->children[side]->color = BLACK;
	else if (color(deleted) == BLACK)
		return (TREE_HAS_ONE_BLACK_LESS);
	return (GOOD);
}

static enum e_tree_state	remove_successor(
		struct s_rbtree **const node,
		struct s_rbtree **const successor,
		int side)
{
	enum e_tree_state	state;

	if ((*node)->children[side] == NULL)
	{
		*successor = *node;
		state = delete_node(node, !side);
	}
	else
		state = balance_subtree(node, side,
				remove_successor(&(*node)->children[side], successor, LEFT));
	return (state);
}

static enum e_tree_state	replace_node(struct s_rbtree **const tree)
{
	enum e_tree_state	subtree_state;
	struct s_rbtree		*successor;

	if ((*tree)->children[LEFT] == NULL || (*tree)->children[RIGHT] == NULL)
		subtree_state = delete_node(tree, (*tree)->children[LEFT] == NULL);
	else
	{
		subtree_state = remove_successor(&(*tree)->children[RIGHT],
				&successor,
				LEFT);
		*successor = **tree;
		*tree = successor;
		subtree_state = balance_subtree(tree, RIGHT, subtree_state);
	}
	return (subtree_state);
}

static enum e_tree_state	remove_recurse(struct s_rbtree **const tree,
		void const *const criterion,
		struct s_rbtree const **removed,
		int (*diff)(void const*, void const*))
{
	int					diff_result;
	enum e_tree_state	subtree_state;

	if (*tree == NULL)
		return (GOOD);
	diff_result = diff(*tree, criterion);
	if (diff_result != 0)
	{
		subtree_state = remove_recurse(
				&(*tree)->children[diff_result <= 0],
				criterion, removed, diff);
		subtree_state = balance_subtree(tree, diff_result <= 0, subtree_state);
	}
	else
	{
		*removed = *tree;
		subtree_state = replace_node(tree);
	}
	return (subtree_state);
}

void						*rbtree_remove(
		struct s_rbtree **tree,
		void const *criterion,
		int (*diff)(void const*, void const*))
{
	struct s_rbtree const *removed;

	removed = NULL;
	if (remove_recurse(tree, criterion, &removed, diff)
			== TREE_HAS_ONE_BLACK_LESS)
		;
	return ((void*)removed);
}
