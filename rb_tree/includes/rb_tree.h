/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 12:19:15 by                   #+#    #+#             */
/*   Updated: 2019/03/25 12:19:15 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_TREE_H
# define RB_TREE_H

struct s_btree
{
	struct s_btree	*right;
	struct s_btree	*left;
};

enum e_color
{
	RED,
	BLACK
};

enum e_tree_insert_ret
{
	NOTHING,
	CHILD_INSERTION,
	GRAND_CHILD_INSERTION // LEFT /RIGHT ?
};

struct s_rbtree
{
	struct s_btree	nodes;
	enum e_color	color;
};

#endif
