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
#define SIZE_TEST 3

int main(void)
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
		rbtree_insert(&tree, &values[index].node, rbtree_test_diff);
		index++;
	}
	index--;
	while (rbtree_remove(&tree, &index, rbtree_test_diff) != NULL)
		index--;
	printf("Remaining nodes : %d\n", index);
	return (!(index == 0));
}
