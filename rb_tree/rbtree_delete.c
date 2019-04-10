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


static void	swap_nodes(struct s_rbtree **node_1, struct s_rbtree **node_2)
{
	struct s_rbtree *tmp;
	enum e_color	tmp_color;

	tmp = *node_1;
	*node_1 = *node_2;
	*node_2 = tmp;
	tmp = (*node_1)->children[LEFT];
	(*node_1)->children[LEFT] = (*node_2)->children[LEFT];
	(*node_2)->children[LEFT] = tmp;
	tmp = (*node_1)->children[RIGHT];
	(*node_1)->children[RIGHT] = (*node_2)->children[RIGHT];
	(*node_2)->children[RIGHT] = tmp;
	tmp_color = (*node_1)->color;
	(*node_1)->color = (*node_2)->color;
	(*node_2)->color = tmp_color;
}

static enum e_tree_state	delete_node(struct s_rbtree ** const node)
{
	struct s_rbtree * const	deleted = *node;

	*node = (*node)->children[RIGHT];
	if (deleted->color == BLACK)
	{
		if (deleted->children[RIGHT]->color == RED)
			deleted->children[RIGHT]->color = BLACK;
		else
			return (TREE_HAS_ONE_BLACK_LESS);
	}
	return (GOOD);
}

static enum e_tree_state swap_with_successor(
		struct s_rbtree ** const node,
		struct s_rbtree ** const predecessor)
{
	if ((*node)->children[LEFT] == NULL)
	{
		swap_nodes(node, predecessor);
		return (balance_subtree(node, delete_node(node)));
	}
	else
		return (swap_with_successor(&(*node)->children[LEFT], predecessor));
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
		subtree_state = remove_recurse(
			diff_result > 0 ? &(*tree)->children[LEFT] : &(*tree)->children[RIGHT],
			criterion, removed, diff);
	else
	{
		*removed = *tree;
		subtree_state = swap_with_successor(&(*tree)->children[RIGHT], tree);
	}
	return (balance_subtree(tree, subtree_state));
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
