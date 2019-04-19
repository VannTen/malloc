/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree_convert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 14:04:46 by                   #+#    #+#             */
/*   Updated: 2019/04/19 14:04:46 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rb_tree.h"
#include <stddef.h>

struct s_rbtree	*rbtree_from_sequential(
		void *first,
		void *(*next)(void *),
		int (*cmp)(void const *, void const *))
{
	struct s_rbtree *new_tree;

	new_tree = NULL;
	while (first != NULL)
	{
		rbtree_insert(&tree, first, cmp);
		first = next(first);
	}
	return (tree);
}
