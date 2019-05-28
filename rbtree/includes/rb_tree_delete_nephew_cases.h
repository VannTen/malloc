/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree_delete_nephew_cases.h                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:58:29 by                   #+#    #+#             */
/*   Updated: 2019/05/28 15:58:29 by                  ###   ########.fr       */
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
