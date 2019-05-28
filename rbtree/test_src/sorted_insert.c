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
#include <stdlib.h>
#ifndef SIZE_TEST
# define SIZE_TEST 5000
#endif

int	main(void)
{
	struct s_test_node	*values;
	int					index;
	struct s_rbtree		*tree;
	int					error;

	values = malloc((SIZE_TEST) * sizeof(*values));
	index = 0;
	while (index < SIZE_TEST)
	{
		values[index].value = index;
		index++;
	}
	tree = rbtree_from_sequential(values,
			array_next_test_node,
			rbtree_test_cmp, values + SIZE_TEST);
	error = !is_valid_rb_tree(tree) + (!tree_is_inorder(tree)) * 2;
	return (error);
}
