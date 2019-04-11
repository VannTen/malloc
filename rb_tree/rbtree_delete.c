/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree_delete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:43:54 by                   #+#    #+#             */
/*   Updated: 2019/04/04 15:43:54 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rb_tree.h"
#include <assert.h>
#include <stddef.h>

/*
** temporary pointers are necessary, since one of the parameters could be
** pointing to one of the child of the other params, creating aliasing problems
** (case of swapping a parent with its direct child)
*/

static void	swap_nodes(struct s_rbtree **node_1, struct s_rbtree **node_2)
{
	struct s_rbtree			tmp;
	struct s_rbtree			*tmp_addr;
	struct s_rbtree * const nodes[] = {*node_1, *node_2};

	tmp_addr = *node_1;
	*node_1 = *node_2;
	*node_2 = tmp_addr;
	tmp.color = nodes[0]->color;
	tmp.children[LEFT] = nodes[0]->children[LEFT];
	tmp.children[RIGHT] = nodes[0]->children[RIGHT];
	nodes[0]->color = nodes[1]->color;
	nodes[0]->children[LEFT] = nodes[1]->children[LEFT];
	nodes[0]->children[RIGHT] = nodes[1]->children[RIGHT];
	nodes[1]->color = tmp.color;
	nodes[1]->children[LEFT] = tmp.children[LEFT];
	nodes[1]->children[RIGHT] = tmp.children[RIGHT];
}

static enum e_tree_state	delete_node(struct s_rbtree ** const node, int side)
{
	struct s_rbtree * const	deleted = *node;

	*node = (*node)->children[side];
	if (color(deleted) == BLACK)
	{
		if (color(deleted->children[side]) == RED)
			deleted->children[side]->color = BLACK;
		else
			return (TREE_HAS_ONE_BLACK_LESS);
	}
	return (GOOD);
}

static enum e_tree_state swap_with_successor(
		struct s_rbtree ** node,
		struct s_rbtree ** const predecessor,
		int side)
{
	enum e_tree_state	state;

	assert(*node != NULL);
	if ((*node)->children[side] == NULL)
	{
		swap_nodes(node, predecessor);
		node = predecessor;
		state = delete_node(node, !side);
	}
	else
		state = swap_with_successor(&(*node)->children[side], predecessor, LEFT);
	return (balance_subtree(node, side, state));
}

static enum e_tree_state remove_recurse(struct s_rbtree ** const tree,
		void const * const criterion,
		struct s_rbtree const ** removed,
		int (*diff)(void const*, void const*))
{
	int						diff_result;
	enum e_tree_state	subtree_state;

	if (*tree == NULL)
		return (GOOD);
	diff_result = diff(*tree, criterion);
	if (diff_result != 0)
		subtree_state = remove_recurse(&(*tree)->children[diff_result <= 0],
			criterion, removed, diff);
	else
	{
		*removed = *tree;
		subtree_state = swap_with_successor(tree, tree, RIGHT);
	}
	return (balance_subtree(tree, diff_result <= 0,subtree_state));
}

void	*rbtree_remove(struct s_rbtree **tree, void const *criterion,
		int (*diff)(void const*, void const*))
{
	struct s_rbtree const * removed;

	removed = NULL;
	if (remove_recurse(tree, criterion, &removed, diff)
			== TREE_HAS_ONE_BLACK_LESS)
		; // No need to do anything

	return ((void*)removed);
}
