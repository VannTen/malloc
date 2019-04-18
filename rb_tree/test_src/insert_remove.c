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
#include "rb_tree_test.h"
#include <stdlib.h>
#include <stdio.h>
#define SIZE_TEST 9

void	assert_order(void const *node, void *_previous_value)
{
	struct s_test_node const * const	value = node;
	int * const						previous_value = _previous_value;

	assert(value->value >= *previous_value);
	*previous_value = value->value;
}

int	test_2(void)
{
	struct s_test_node	*values;
	struct s_rbtree		*tree;
	size_t				index;
	int					value;
	int					assert_val;

	tree = NULL;
	index = 0;
	values = malloc(SIZE_TEST * sizeof (*values));
	while (index < SIZE_TEST)
	{
		values[index].value = rand();
		rbtree_init_node(&(values[index].node));
		rbtree_insert(&tree, &(values[index].node), rbtree_test_cmp);
		assert_val = 0;
		rbtree_inorder_traversal(tree, assert_order, &assert_val);
		index++;
	}
	while (index != 0)
	{
		index--;
		value = values[index].value;
		rbtree_remove(&tree, &value, rbtree_test_diff);
		printf("===============================%zu\n", index);
		print_tree(tree);
		assert(is_valid_rb_tree(tree));
		assert_val = 0;
		rbtree_inorder_traversal(tree, assert_order, &assert_val);
	}
	free(values);
	return (1);
}

#define SIZE_TEST_1 3
int	test_1(void)
{
	struct s_test_node	values[SIZE_TEST_1];
	struct s_rbtree		*tree;
	size_t				index;
	int					value;
	struct s_test_node	*addr;

	tree = NULL;
	index = 0;
	while (index < SIZE_TEST_1)
	{
		values[index].value = index + 4;
		rbtree_init_node(&(values[index].node));
		rbtree_insert(&tree, &(values[index].node), rbtree_test_cmp);
		index++;
	}
	assert(is_valid_rb_tree(tree));
	print_tree(tree);
	while (index != 0)
	{
		index--;
		value = index + 4;
		addr = rbtree_remove(&tree, &value, rbtree_test_diff);
		assert(value == addr->value);
		assert(is_valid_rb_tree(tree));
		printf("===============================%zu\n", index);
		print_tree(tree);
	}
	return (1);
}

int	main(void)
{
	return (!(test_1() && test_2()));
}
