/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 11:57:42 by                   #+#    #+#             */
/*   Updated: 2019/04/10 11:57:42 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include "rb_tree.h"

struct test_node {

	struct s_rbtree	node;
	int				value;
};


static int	cmp(void const *val_1, void const *val_2)
{
	return (((struct test_node const *)val_1)->value
			- ((struct test_node const *)val_2)->value);
}

int	main(void)
{
	struct test_node	values[10];
	struct s_rbtree		*tree;
	size_t				index;
	int					value;

	tree = NULL;
	index = 0;
	while (index < 10)
	{
		values[index].value = index + 4;
		rbtree_init_node(&(values[index].node));
		rbtree_insert(&tree, &(values[index].node), cmp);
		index++;
	}
	while (index > 5)
	{
		value = index + 4;
		rbtree_remove(&tree, &value, cmp);
		index--;
		assert(is_valid_rb_tree(tree));
	}
	assert(black_depth(tree) != 0);
	assert(max_depth(tree) <= min_depth(tree) * 2);
	return (1);
}
