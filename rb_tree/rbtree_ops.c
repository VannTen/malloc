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

static void grand_parent_become_red(struct s_rbtree *grand_parent)
{
	assert(grand_parent->children[LEFT]->color == RED && grand_parent->children[RIGHT]->color == RED);
	grand_parent->color = RED;
	grand_parent->children[LEFT]->color = BLACK;
	grand_parent->children[RIGHT]->color = BLACK;
}

static void insert_repair_rotation(
		struct s_rbtree **grand_parent,
		int side)
{
	if (color((*grand_parent)->children[side]->children[!side]) == RED)
		rotate(&(*grand_parent)->children[side], side);
	rotate(grand_parent, !side);
	(*grand_parent)->children[!side]->color = RED;
	(*grand_parent)->color = BLACK;
}

static enum e_tree_insert_ret	repair_tree(
		struct s_rbtree **node,
		int side,
		enum e_tree_insert_ret state)
{
	if (state == NEW_RED_CHILD && (*node)->color == RED)
		return (NEW_RED_GRAND_CHILD);
	else if (state == NEW_RED_GRAND_CHILD)
	{
		if (color((*node)->children[!side]) == RED)
		{
			grand_parent_become_red(*node);
			return (NEW_RED_CHILD);
		}
		else
			insert_repair_rotation(node, side);
	}
	return (NOTHING);
}

static enum e_tree_insert_ret	insert(
	struct s_rbtree ** tree,
	struct s_rbtree *new_node,
	int (*diff)(void const*, void const*))
{
	int							side;

	if (*tree == NULL)
	{
		*tree = new_node;
		return (NEW_RED_CHILD);
	}
	else
	{
		side = diff(*tree, new_node) <= 0;
		return (repair_tree(
					tree,
					side,
					insert(&(*tree)->children[side], new_node, diff)));
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
