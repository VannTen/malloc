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

#include "rb_tree_test.h"

int	main(void)
{
	struct s_test_node	values[100];
	struct s_rbtree		*tree;
	int					index;

	index = 0;
	while (index < 100)
	{
		values[index].value = index;
		rbtree_init_node(&(values[index].node));
		rbtree_insert(&tree, &(values[index].node), rbtree_test_cmp);
		index++;
	}
	return (!(btree_search(tree, &index, rbtree_test_diff) == NULL));
}
