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
#include <stdlib.h>
#include <stdio.h>
#define SIZE_TEST 9

struct test_node {

	struct s_rbtree	node;
	int				value;
};

static int	cmp(void const *val_1, void const *val_2)
{
	return (((struct test_node const *)val_1)->value
			- ((struct test_node const *)val_2)->value);
}

static int diff(void const *val_1, void const *crit)
{
	return (((struct test_node const *)val_1)->value
			- *(int*)crit);
}

void	assert_order(void const *node, void *_previous_value)
{
	struct test_node const * const	value = node;
	int * const						previous_value = _previous_value;

	assert(value->value >= *previous_value);
	*previous_value = value->value;
}

int	test_2(void)
{
	struct test_node	*values;
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
		rbtree_insert(&tree, &(values[index].node), cmp);
		assert_val = 0;
		rbtree_inorder_traversal(tree, assert_order, &assert_val);
		index++;
	}
	while (index != 0)
	{
		index--;
		value = values[index].value;
		rbtree_remove(&tree, &value, diff);
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
	struct test_node	values[SIZE_TEST_1];
	struct s_rbtree		*tree;
	size_t				index;
	int					value;
	struct test_node	*addr;

	tree = NULL;
	index = 0;
	while (index < SIZE_TEST_1)
	{
		values[index].value = index + 4;
		rbtree_init_node(&(values[index].node));
		rbtree_insert(&tree, &(values[index].node), cmp);
		index++;
	}
	assert(is_valid_rb_tree(tree));
	print_tree(tree);
	while (index != 0)
	{
		index--;
		value = index + 4;
		addr = rbtree_remove(&tree, &value, diff);
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
