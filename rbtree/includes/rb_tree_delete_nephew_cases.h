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

#ifndef RB_TREE_DELETE_NEPHEW_CASES_H
# define RB_TREE_DELETE_NEPHEW_CASES_H
# include "rb_tree.h"

void	parent_sibling_nephews_black(
		struct s_rbtree **tree,
		int side);
void	parent_red_sib_neph_black(struct s_rbtree **tree, int side);
void	outer_red_nephew(struct s_rbtree **tree, int side);
void	inner_red_nephew(struct s_rbtree **tree, int side);

#endif
