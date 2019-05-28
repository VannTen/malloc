/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placeholder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgautier <mgautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 11:10:44 by mgautier          #+#    #+#             */
/*   Updated: 2019/05/28 11:10:44 by mgautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <assert.h>
#include "rb_tree.h"

struct s_rbtree const	*btree_search(struct s_rbtree const *node,
		void const *data,
		int (*cmp)(void const*, void const*))
{
	int result;

	if (node == NULL)
		return (NULL);
	result = cmp(node, data);
	if (result == 0)
		return node;
	else
		return (btree_search(
					node->children[result <= 0],
					data,
					cmp));
}

void	left_rotate(struct s_rbtree ** root)
{
	struct s_rbtree * pivot;

	assert(*root != NULL && (*root)->children[RIGHT] != NULL);
	pivot = (*root)->children[RIGHT];
	(*root)->children[RIGHT] = pivot->children[LEFT];
	pivot->children[LEFT] = *root;
	*root = pivot;
}

void	right_rotate(struct s_rbtree ** root)
{
	struct s_rbtree * pivot;

	assert(*root != NULL && (*root)->children[LEFT] != NULL);
	pivot = (*root)->children[LEFT];
	(*root)->children[LEFT] = pivot->children[RIGHT];
	pivot->children[RIGHT]= *root;
	*root = pivot;
}

void	rotate(struct s_rbtree **parent, int side)
{
	(side == LEFT ? left_rotate : right_rotate)(parent);
}

void	rbtree_inorder_traversal(
		struct s_rbtree const * tree,
		void (*f)(void const *, void *),
		void *extern_context)
{
	if (tree != NULL)
	{
		rbtree_inorder_traversal(tree->children[LEFT], f, extern_context);
		f(tree, extern_context);
		rbtree_inorder_traversal(tree->children[RIGHT], f, extern_context);
	}
}
