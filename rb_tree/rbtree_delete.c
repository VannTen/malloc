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


static struct s_rbtree **find_successor_or_predecessor(
		struct s_rbtree const *node,
		int successor)
{
	struct s_rbtree **replacer;

	replacer = &node;
	while (1)
	{
		replacer = successor ? &(*replacer)->left : &(*replacer)->right;
		if ((successor ? *replacer->left : *replacer->right) == NULL)
			break ;
	}
	return (replacer);
}

static void	swap_nodes(struct s_rbtree **node_1, struct s_rbtree **node_2)
{
	struct s_rbtree *tmp;

	tmp = *node_1;
	*node_1 = node_2;
	*node_2 = tmp;
	tmp = (*node_1)->left;
	(*node_1)->left = node_2->left;
	(*node_2)->left = tmp;
	tmp = (*node_1)->right;
	(*node_1)->right = node_2->right;
	(*node_2)->right = tmp;
	if ((*node_1)->color != (*node_2)->color)
	{
		(*node_1)->color = !(*node_1)->color;
		(*node_2)->color = !(*node_2)->color;
	}
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
		return (criterion == NULL ? REPLACER_FOUND : NOTHING);
	if (criterion != NULL)
	{
		diff_result = diff(*tree, criterion);
		if (diff_result != 0)
			subtree = diff_result > 0 ? &(*tree)->left : &(*tree)->right;
		else
		{
			*removed = *tree;
			criterion = NULL;
			removed = tree;
			subtree = &(*tree)->right;
		}
	}
	else
		subtree = &(*tree)->left;
	subtree_state = remove_recurse(subtree, criterion, removed, diff);
	return (balance_tree(tree, subtree_state));
}

void	*rbtree_remove(struct s_rbtree **tree, void const *criterion,
		int (*diff)(void const*, void const*))
{
	struct s_rbtree * removed;

	removed = NULL;
	if (remove_recurse( tree, criterion, &removed, diff)
			== TREE_HAS_ONE_BLACK_LESS)
		; // No need to do anything

	return (removed)
}
