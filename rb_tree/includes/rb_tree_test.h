/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree_test.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 13:52:40 by                   #+#    #+#             */
/*   Updated: 2019/04/18 13:52:40 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_TREE_TEST_H
# define RB_TREE_TEST_H
# include "rb_tree.h"


struct s_test_node {

	struct s_rbtree	node;
	int				value;
};

/*
** Examples function to be passed as pointers
** They expect rb_tree stocking simple ints
*/

int	rbtree_test_cmp(void const *val_1, void const *val_2);
int rbtree_test_diff(void const *val_1, void const *crit);

/*
** Printing and debugging
*/

void	print_tree_content(struct s_rbtree const *tree);
void	print_tree(struct s_rbtree const *tree);

#endif
