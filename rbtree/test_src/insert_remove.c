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

#include <assert.h>
#include "rb_tree.h"
#include "rb_tree_test.h"
#include <stdlib.h>
#include <stdio.h>
#define SIZE_TEST 5000

void	assert_order(void const *node, void *v_previous_value)
{
	struct s_test_node const *const	value = node;
	int *const						previous_value = v_previous_value;

	assert(value->value >= *previous_value);
	*previous_value = value->value;
}

void	init_values_2(struct s_test_node *values, struct s_rbtree **tree)
{
	int		assert_val;
	size_t	index;

	index = 0;
	while (index < SIZE_TEST)
	{
		values[index].value = rand();
		rbtree_init_node(&(values[index].node));
		rbtree_insert(tree, &(values[index].node), rbtree_test_cmp);
		assert_val = 0;
		rbtree_inorder_traversal(*tree, assert_order, &assert_val);
		index++;
	}
}

void	init_values_1(struct s_test_node *values, struct s_rbtree **tree)
{
	int		assert_val;
	size_t	index;

	index = 0;
	while (index < SIZE_TEST)
	{
		values[index].value = index;
		rbtree_init_node(&(values[index].node));
		rbtree_insert(tree, &(values[index].node), rbtree_test_cmp);
		assert_val = 0;
		rbtree_inorder_traversal(*tree, assert_order, &assert_val);
		index++;
	}
}

int		test_2(void)
{
	struct s_test_node	*values;
	struct s_rbtree		*tree;
	size_t				index;
	int					value;
	struct s_test_node	*val;

	tree = NULL;
	index = 0;
	values = malloc(sizeof(*values) * SIZE_TEST);
	init_values_2(values, &tree);
	index = SIZE_TEST;
	while ((val = rbtree_remove(&tree, &index, rbtree_test_diff)) != NULL)
	{
		value = values[index].value;
		assert(is_valid_rb_tree(tree));
		assert(tree_is_inorder(tree));
	}
	free(values);
	return (1);
}

int		main(void)
{
	struct s_test_node	values[SIZE_TEST];
	struct s_rbtree		*tree;
	size_t				index;
	int					value;
	struct s_test_node	*addr;

	tree = NULL;
	index = SIZE_TEST;
	init_values_1(values, &tree);
	assert(is_valid_rb_tree(tree));
	assert(tree_is_inorder(tree));
	print_tree(tree);
	while (index != 0)
	{
		index--;
		value = index;
		addr = rbtree_remove(&tree, &value, rbtree_test_diff);
		printf("===============================%zu\n", index);
		print_tree(tree);
		assert(is_valid_rb_tree(tree));
		assert(value == addr->value);
	}
	return (!(test_2()));
}
