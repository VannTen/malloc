/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_extraction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 13:44:20 by                   #+#    #+#             */
/*   Updated: 2019/04/18 13:44:20 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rb_tree.h"
#include "rb_tree_test.h"
#include <stddef.h>
#include <stdio.h>
#include <assert.h>
#define SIZE_TEST 5000

int main(void)
{
	struct s_test_node	values[SIZE_TEST];
	int					index;
	struct s_rbtree		*tree;
	struct s_test_node	*val;

	index = 0;
	tree = NULL;
	while (index < SIZE_TEST)
	{
		values[index].value = index;
		rbtree_init_node(&values[index].node);
		rbtree_insert(&tree, &values[index].node, rbtree_test_cmp);
		print_tree_content(tree);
		print_tree(tree);
		printf("=======\n");
		index++;
	}
	assert(tree_is_inorder(tree));
	index--;
	while ((val = rbtree_remove(&tree, &index, rbtree_test_diff)) != NULL)
	{
		assert(tree_is_inorder(tree));
		print_tree_content(tree);
		printf("=======%d %d \n", index, val->value);
		index--;
	}
	printf("Remaining nodes : %d\n", index);
	if (index != 0)
		print_tree_content(tree);
	return (!(index == -1));
}
