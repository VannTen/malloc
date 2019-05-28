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
#include "rb_tree_test.h"
#include <stddef.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#define SIZE_TEST 1000000

void		check_tree_order(void const *value, void *previous)
{
	int	const	new_value = ((struct s_test_node const *)value)->value;

	assert(*(int*)previous <= new_value);
	*(int*)previous = new_value;
}

int			test_2(void)
{
	struct s_test_node	*values;
	struct s_rbtree		*tree;
	size_t				index;
	int					value;

	tree = NULL;
	index = 0;
	values = malloc(sizeof(*values) * SIZE_TEST);
	while (index < SIZE_TEST)
	{
		values[index].value = rand();
		rbtree_init_node(&(values[index].node));
		rbtree_insert(&tree, &(values[index].node), rbtree_test_cmp);
		index++;
	}
	value = 0;
	rbtree_inorder_traversal(tree, check_tree_order, &value);
	assert(black_depth(tree) != 0);
	assert(max_depth(tree) <= min_depth(tree) * 2);
	free(values);
	return (1);
}

int			test_1(void)
{
	struct s_test_node	values[10];
	struct s_rbtree		*tree;
	size_t				index;
	int					value;

	tree = NULL;
	index = 0;
	while (index < 10)
	{
		values[index].value = index + 4;
		rbtree_init_node(&(values[index].node));
		rbtree_insert(&tree, &(values[index].node), rbtree_test_cmp);
		index++;
	}
	value = 0;
	rbtree_inorder_traversal(tree, check_tree_order, &value);
	assert(black_depth(tree) != 0);
	assert(max_depth(tree) <= min_depth(tree) * 2);
	return (1);
}

int			main(void)
{
	return (!(test_1() && test_2()));
}
