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
# define SIZE_TEST 50
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
		values[index].value = rand();
		index++;
	}
	tree = rbtree_from_sequential(values,
			array_next_test_node,
			rbtree_test_cmp, values + SIZE_TEST);
	index--;
	while (rbtree_remove(&tree, &values[index].value, rbtree_test_diff) != NULL)
	{
		print_tree_content(tree);
		index--;
		printf("=================================%d\n", values[index].value);
	}
	print_tree_content(tree);
	printf("%d\n", values[index + 1].value);
	return (index + 1);
}
