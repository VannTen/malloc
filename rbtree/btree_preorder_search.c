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

#include "rb_tree.h"
#include <stddef.h>

struct s_rbtree const	*btree_preorder_search(struct s_rbtree const *node,
		void const *ref_data,
		int (*match)(struct s_rbtree const *node, void const *ref_data))
{
	struct s_rbtree const	*result;

	if (node != NULL)
	{
		if (match(node, ref_data))
			return (node);
		result = btree_preorder_search(node->children[LEFT], ref_data, match);
		return (result != NULL
				? result : btree_preorder_search(
					node->children[RIGHT], ref_data, match));
	}
	return (NULL);
}
