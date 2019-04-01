/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 16:30:00 by                   #+#    #+#             */
/*   Updated: 2019/03/25 16:30:00 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rb_tree.h"
#include <assert.h>
#include <stddef.h>

static struct s_rbtree const *sibling(
		struct s_rbtree *cur_node,
		struct s_rbtree const * child)
{
	return (child == cur_node->left ? cur_node->left : cur_node->right);
}

static void grand_parent_become_red(struct s_rbtree *grand_parent)
{
	assert(grand_parent->left->color == RED && grand_parent->right->color == RED);
	grand_parent->color = RED;
	grand_parent->left->color = BLACK;
	grand_parent->right->color = BLACK;
}

static void insert_repair_rotation(
		struct s_rbtree **grand_parent,
		struct s_rbtree *child)
{
	int const	left = (*grand_parent)->left == child;

	if (left && (*grand_parent)->left->right->color == RED)
		left_rotate(&(*grand_parent)->left);
	else if (!left && child->right->left->color == RED)
		right_rotate(&(*grand_parent)->right);
	if (left)
	{
		right_rotate(grand_parent);
		(*grand_parent)->right->color = RED;
	}
	else
	{
		left_rotate(grand_parent);
		(*grand_parent)->left->color = RED;
	}
	(*grand_parent)->color = BLACK;
}

static enum e_tree_insert_ret	repair_tree(
		struct s_rbtree **node,
		struct s_rbtree **child,
		enum e_tree_insert_ret state)
{
	if (state == NEW_RED_CHILD && (*node)->color == RED)
		return (NEW_RED_GRAND_CHILD);
	else if (state == NEW_RED_GRAND_CHILD)
	{
		if (sibling(*node, *child)->color == RED)
		{
			grand_parent_become_red(*node);
			return (NEW_RED_CHILD);
		}
		else
			insert_repair_rotation(node, *child);
	}
	return (NOTHING);
}

static enum e_tree_insert_ret	insert(
	struct s_rbtree ** tree,
	struct s_rbtree *new_node,
	int (*cmp)(void const*, void const*))
{
	enum e_tree_insert_ret		ret;
	struct s_rbtree ** const	child
		= cmp(*tree, new_node) < 0 ? &(*tree)->left : &(*tree)->right;

	if (*tree == NULL)
	{
		*tree = new_node;
		return (NEW_RED_CHILD);
	}
	else
		ret = insert(child, new_node, cmp);
	return (repair_tree(tree, child, ret));
}

void	rbtree_insert(
	struct s_rbtree ** tree,
	struct s_rbtree *new_node,
	int (*cmp)(void const*, void const*))
{
	if (NEW_RED_CHILD == insert(tree, new_node, cmp))
		(*tree)->color = BLACK;
}
