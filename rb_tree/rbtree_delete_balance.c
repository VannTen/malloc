/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree_delete_balance.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:29:01 by                   #+#    #+#             */
/*   Updated: 2019/04/08 17:29:01 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rb_tree.h"


enum e_remove_ret	balance_subtree(
		struct s_rbtree ** const tree,
// Which child ?
		enum e_remove_ret subtree_state)
{
	if (subtree_state == TREE_HAS_ONE_BLACK_LESS)
	{
		if ((*tree)->other_child->color == RED)
			;
		else if ((*tree)->other_child->outer_child->color == RED)
			;
		else if ((*tree)->other_child->inner_child->color == RED
					&& (*tree)->other_child->outer_child->color == BLACK)
			;
		else if ((*tree)->color == BLACK
			&& (*tree)->other_child == == BLACK_CHILDS)
			;
		else if ((*tree)->other_child == == BLACK_CHILDS
				&& (*tree)->color == RED)
			;
	}
	return (subtree_state);
}
