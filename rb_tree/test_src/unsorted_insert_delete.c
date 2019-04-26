/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_insert_delete.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 14:19:47 by                   #+#    #+#             */
/*   Updated: 2019/04/19 14:19:47 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rb_tree.h"
#include "rb_tree_test.h"
#include <stdlib.h>
#include <stdio.h>
#ifndef SIZE_TEST
# define SIZE_TEST 100
#endif

int main(void)
{
	struct s_test_node	*values;
	int					index;
	struct s_rbtree		*tree;

	values = malloc((SIZE_TEST)* sizeof (*values));
	index = 0;
	while (index < SIZE_TEST)
	{
		values[index].value = rand() % SIZE_TEST;
		index++;
	}
	tree = rbtree_from_sequential(values,
			array_next_test_node,
			rbtree_test_cmp, values + SIZE_TEST);
	index--;
	while (rbtree_node_count(tree) == (size_t)index + 1)
	{
		print_tree_content(tree);
		rbtree_remove(&tree, &values[index].value, rbtree_test_diff);
		index--;
		if (index < 0)
			break ;
		printf("=================================%d\n", values[index].value);
	}
	print_tree_content(tree);
	printf("%zu=================================%d\n", rbtree_node_count(tree), values[index].value);
	return (index + 1);
}
