/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree_test_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 13:55:21 by                   #+#    #+#             */
/*   Updated: 2019/04/18 13:55:21 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rb_tree.h"
#include "rb_tree_test.h"

int	rbtree_test_cmp(void const *val_1, void const *val_2)
{
	return (((struct s_test_node const *)val_1)->value
			- ((struct s_test_node const *)val_2)->value);
}

int rbtree_test_diff(void const *val_1, void const *crit)
{
	return (((struct s_test_node const *)val_1)->value
			- *(int*)crit);
}

static void	acc(void const *_node, void *prev_val)
{
	struct s_test_node const * const	node = _node;
	int * const							val = prev_val;

	val[1] = val[1] && node->value >= val[0];
	val[0] = node->value;

}

int	tree_is_inorder(struct s_rbtree const *tree)
{
	int value[2];

	value[0] = 0;
	value[1] = (0 == 0);
	rbtree_inorder_traversal(tree, acc, value);
	return (value[1]);
}

void	*array_next_test_node(void * node)
{
	return (((struct s_test_node *)node) + 1);
}
