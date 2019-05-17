/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_element_not_present.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 15:29:06 by                   #+#    #+#             */
/*   Updated: 2019/05/17 15:29:06 by                  ###   ########.fr       */
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
