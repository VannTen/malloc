/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_odering.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 14:23:53 by                   #+#    #+#             */
/*   Updated: 2019/04/01 14:23:53 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rb_tree.h"
#include <stddef.h>
#include <assert.h>
#include <stdlib.h>

struct test_node {

	struct s_rbtree	node;
	int				value;
};


static int	cmp(void const *val_1, void const *val_2)
{
	return (((struct test_node const *)val_1)->value
			- ((struct test_node const *)val_2)->value);
}

void	check_tree_order(void const *val_1)
{
	static int	previous_value = 0;

	assert(previous_value < ((struct test_node const *)val_1)->value);
	previous_value = ((struct test_node const *)val_1)->value;
}

int main(void)
{
	struct test_node	values[100];
	struct s_rbtree		*tree;
	size_t				index;

	tree = NULL;
	index = 0;
	while (index < 10)
	{
		values[index].value = index + 4;
		rbtree_init_node(&(values[index].node));
		rbtree_insert(&tree, &(values[index].node), cmp);
		index++;
	}
	rbtree_inorder_traversal(tree, check_tree_order);
	assert(black_depth(tree) != 0);
	assert(max_depth(tree) <= min_depth(tree) * 2);
}
