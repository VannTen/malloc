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

#include <stddef.h>
#include <assert.h>
#include "rb_tree.h"

struct s_rbtree const	*btree_search(struct s_rbtree const *node,
		void *data,
		int (*cmp)(void const*, void const*))
{
	int const result = cmp(data, node);

	if (result == 0)
		return node;
	else
		return (btree_search(
					result < 0 ? node->children[LEFT] : node->children[RIGHT],
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
