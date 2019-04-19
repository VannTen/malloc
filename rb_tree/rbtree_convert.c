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
		int (*cmp)(void const *, void const *),
		void * const end_address)
{
	struct s_rbtree *new_tree;

	new_tree = NULL;
	while (first != end_address)
	{
		rbtree_init_node(first);
		rbtree_insert(&new_tree, first, cmp);
		first = next(first);
	}
	return (new_tree);
}
