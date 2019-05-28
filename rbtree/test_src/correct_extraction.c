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
#include <stdio.h>
#include <assert.h>
#define SIZE_TEST 5000

void	delete_the_tree(struct s_rbtree *tree, int *index)
{
	struct s_test_node	*val;

	while ((val = rbtree_remove(&tree, index, rbtree_test_diff)) != NULL)
	{
		assert(tree_is_inorder(tree));
		print_tree_content(tree);
		printf("=======%d %d \n", *index, val->value);
		(*index)--;
	}
}

int		main(void)
{
	struct s_test_node	values[SIZE_TEST];
	int					index;
	struct s_rbtree		*tree;

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
	delete_the_tree(tree, &index);
	printf("Remaining nodes : %d\n", index);
	if (index != 0)
		print_tree_content(tree);
	return (!(index == -1));
}
