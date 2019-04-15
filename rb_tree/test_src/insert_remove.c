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
#define SIZE_TEST 10

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
	index--;
	while (index != 0)
	{
		value = values[index].value;
		rbtree_remove(&tree, &value, diff);
		index--;
		assert(is_valid_rb_tree(tree));
	}
	free(values);
	return (1);
}

int	test_1(void)
{
	struct test_node	values[20];
	struct s_rbtree		*tree;
	size_t				index;
	int					value;

	tree = NULL;
	index = 0;
	while (index < 20)
	{
		values[index].value = index + 4;
		rbtree_init_node(&(values[index].node));
		rbtree_insert(&tree, &(values[index].node), cmp);
		index++;
	}
	while (index != 0)
	{
		value = index + 4;
		rbtree_remove(&tree, &value, diff);
		index--;
		assert(is_valid_rb_tree(tree));
	}
	assert(black_depth(tree) != 0);
	assert(max_depth(tree) <= min_depth(tree) * 2);
	return (1);
}

int	main(void)
{
	return (!(test_1() && test_2()));
}
