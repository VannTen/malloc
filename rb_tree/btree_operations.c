/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 12:29:57 by                   #+#    #+#             */
/*   Updated: 2019/03/25 12:29:57 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rb_tree.h"
#include <assert.h>

void	*btree_search(struct s_btree const *node,
		void *data,
		int (*cmp)(void const*, void const*))
{
	int const result = cmp(data, node);

	if (result == 0)
		return node;
	else
		return (btree_search(result < 0 ? node->left : node->right));
}

struct s_btree	*left_rotate(struct s_btree * root)
{
	struct s_btree * pivot;

	assert(root != NULL && root->right != NULL);
	pivot = root->right;
	root->right = pivot->left;
	pivot->left = root;
	return (pivot);
}

struct s_btree	*right_rotate(struct s_btree * root)
{
	struct s_btree * pivot;

	assert(root != NULL && root->left != NULL);
	pivot = root->left;
	root->left = pivot->right;
	pivot->right= root;
	return (pivot);
}

void			btree_insert(
		struct s_btree const * new_node,
		struct s_btree * tree,
		int (*cmp)(void const*, void const*))
{
	struct s_btree **	parent;

	assert(tree != NULL);
	parent = cmp(new_node, tree) < 0 ? &tree->left : &tree->right;
	if (*parent != NULL)
		btree_insert(new_node, *parent);
	else
		*parent = new_node;
}
