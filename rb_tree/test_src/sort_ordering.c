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
#include <stdio.h>
#include <limits.h>

struct test_node {

	struct s_rbtree	node;
	int				value;
};


static int	cmp(void const *val_1, void const *val_2)
{
	return (((struct test_node const *)val_1)->value
			- ((struct test_node const *)val_2)->value);
}

void	check_tree_order(void const *value, void *previous)
{
	int	const	new_value = ((struct test_node const *)value)->value;

	//printf("%d\n", new_value);
	assert(*(int*)previous <= new_value);
	*(int*)previous = new_value;
}


#define SIZE_TEST INT_MAX / 4096
int	test_2(void)
{
	struct test_node	*values;
	struct s_rbtree		*tree;
	size_t				index;
	int					value;

	tree = NULL;
	index = 0;
	values = malloc(SIZE_TEST * sizeof (*values));
	while (index < SIZE_TEST)
	{
		values[index].value = rand();
		rbtree_init_node(&(values[index].node));
		rbtree_insert(&tree, &(values[index].node), cmp);
		index++;
	}
	value = 0;
	rbtree_inorder_traversal(tree, check_tree_order, &value);
	assert(black_depth(tree) != 0);
	assert(max_depth(tree) <= min_depth(tree) * 2);
	free(values);
	return (1);
}

int test_1(void)
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
	value = 0;
	rbtree_inorder_traversal(tree, check_tree_order, &value);
	assert(black_depth(tree) != 0);
	assert(max_depth(tree) <= min_depth(tree) * 2);
	return (1);
}

int main(void)
{
	return (!(test_1() && test_2()));
}
