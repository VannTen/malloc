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
	*node_1 = node_2;
	*node_2 = tmp;
	tmp = (*node_1)->left;
	(*node_1)->left = node_2->left;
	(*node_2)->left = tmp;
	tmp = (*node_1)->right;
	(*node_1)->right = node_2->right;
	(*node_2)->right = tmp;
	tmp_color = (*node_1)->color;
	(*node_1)->color = (*node_2)->color;
	(*node_2)->color = tmp_color;
}

static enum e_remove_ret	delete_node(struct s_rbtree ** const node)
{
	struct s_rbtree * const	deleted = *node;

	*node = (*node)->right;
	if (deleted->color == BLACK)
	{
		if (deleted->right->color == RED)
			deleted->right->color == BLACK;
		else
			return (TREE_HAS_ONE_BLACK_LESS);
	}
	return (NOTHING);
}

static enum e_remove_ret swap_with_successor(
		struct s_rbtree ** const node,
		struct s_rbtree ** const predecessor)
{
	if ((*node)->left == NULL)
	{
		swap_nodes(node, predecessor);
		return (balance_tree(node, delete_node(node)));
	}
	else
		return (swap_with_successor(&(*node)->left, predecessor));
}

static enum e_remove_ret remove_recurse(struct s_rbtree ** const tree,
		void * const criterion,
		struct s_rbtree const **removed,
		int (*diff)(void const*, void const*))
{
	int						diff_result;
	enum e_tree_remove_ret	subtree_state;
	struct s_rbtree **		subtree;

	if (*tree == NULL)
		return (NOT_FOUND);
	diff_result = diff(*tree, criterion);
	if (diff_result != 0)
		subtree_state = remove_recurse(
			diff_result > 0 ? &(*tree)->left : &(*tree)->right,
			criterion, removed, diff);
	else
		subtree_state = swap_with_successor(&(*tree)->right, tree);
	return (balance_tree(tree, subtree_state));
}

void	*rbtree_remove(struct s_rbtree **tree, void const *criterion,
		int (*diff)(void const*, void const*))
{
	struct s_rbtree * removed;

	removed = NULL;
	if (remove_recurse(tree, criterion, &removed, diff)
			== TREE_HAS_ONE_BLACK_LESS)
		; // No need to do anything

	return (removed)
}
