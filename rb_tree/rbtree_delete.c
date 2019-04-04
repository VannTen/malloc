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

void	*rbtree_remove(struct s_rbtree **tree,
		void *criterion,
		int (*diff)(void const*, void const*))
{
	struct s_rbtree	**replacer;

	tree = find_node_to_remove(tree, criterion, diff);
	replacer_emplacement = find_successor_or_predecessor(*tree);
	swap_nodes(tree, replacer_emplacement);
}
