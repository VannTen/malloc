/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree_test_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 13:55:21 by                   #+#    #+#             */
/*   Updated: 2019/04/18 13:55:21 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rb_tree.h"
#include "rb_tree_test.h"

int	rbtree_test_cmp(void const *val_1, void const *val_2)
{
	return (((struct s_test_node const *)val_1)->value
			- ((struct s_test_node const *)val_2)->value);
}

int rbtree_test_diff(void const *val_1, void const *crit)
{
	return (((struct s_test_node const *)val_1)->value
			- *(int*)crit);
}
