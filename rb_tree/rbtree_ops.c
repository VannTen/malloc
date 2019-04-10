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
	return (cur_node->children[child == cur_node->children[0]]);
}

static void grand_parent_become_red(struct s_rbtree *grand_parent)
{
	assert(grand_parent->children[LEFT]->color == RED && grand_parent->children[RIGHT]->color == RED);
	grand_parent->color = RED;
	grand_parent->children[LEFT]->color = BLACK;
	grand_parent->children[RIGHT]->color = BLACK;
}

static void insert_repair_rotation(
		struct s_rbtree **grand_parent,
		struct s_rbtree *child)
{
	int const	left = (*grand_parent)->children[LEFT] == child;

	if (left && color((*grand_parent)->children[LEFT]->children[RIGHT]) == RED)
		left_rotate(&(*grand_parent)->children[LEFT]);
	else if (!left && color((*grand_parent)->children[RIGHT]->children[LEFT]) == RED)
		right_rotate(&(*grand_parent)->children[RIGHT]);
	if (left)
	{
		right_rotate(grand_parent);
		(*grand_parent)->children[RIGHT]->color = RED;
	}
	else
	{
		left_rotate(grand_parent);
		(*grand_parent)->children[LEFT]->color = RED;
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
		if (color(sibling(*node, *child)) == RED)
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
	int (*diff)(void const*, void const*))
{
	struct s_rbtree **			child;

	if (*tree == NULL)
	{
		*tree = new_node;
		return (NEW_RED_CHILD);
	}
	else
	{
		if (diff(*tree, new_node) > 0)
			child = &(*tree)->children[LEFT];
		else
			child = &(*tree)->children[RIGHT];
		return (repair_tree(
					tree,
					child,
					insert(child, new_node, diff)));
	}
}

void	rbtree_insert(
	struct s_rbtree ** tree,
	struct s_rbtree *new_node,
	int (*cmp)(void const*, void const*))
{
	if (NEW_RED_CHILD == insert(tree, new_node, cmp))
		(*tree)->color = BLACK;
}
