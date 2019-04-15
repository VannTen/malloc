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

static enum e_tree_state	delete_node(struct s_rbtree ** const node, int side)
{
	struct s_rbtree * const	deleted = *node;

	assert(deleted != NULL);
	assert(deleted->children[LEFT] == NULL || deleted->children[RIGHT] == NULL);
	*node = (*node)->children[side];
	if (color(deleted->children[side]) == RED)
		deleted->children[side]->color = BLACK;
	else if (color(deleted) == BLACK)
		return (TREE_HAS_ONE_BLACK_LESS);
	return (GOOD);
}

/*
** The check in delete_node call is required
** to handle the following special case :
** If node is one of the children of predecessor, the pointer pointed by node
** will be corrupted by swap_nodes, since it is
** &(*predecessor)->children[EITHER] , which will be modified when the swap
** exchanges the children of the two nodes.
*/

static enum e_tree_state remove_successor(
		struct s_rbtree ** const node,
		struct s_rbtree ** const successor,
		int side)
{
	enum e_tree_state	state;

	assert(*node != NULL);
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

static enum e_tree_state remove_recurse(struct s_rbtree ** const tree,
		void const * const criterion,
		struct s_rbtree const ** removed,
		int (*diff)(void const*, void const*))
{
	int						diff_result;
	enum e_tree_state	subtree_state;
	struct s_rbtree		*successor;

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
		subtree_state = remove_successor(tree, &successor, RIGHT);
		if (*tree != NULL)
		{
			*successor = **tree;
			*tree = successor;
		}
	}
	return (subtree_state);
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
