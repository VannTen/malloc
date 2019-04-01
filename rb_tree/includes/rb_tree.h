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

enum e_color
{
	RED,
	BLACK
};

enum e_tree_insert_ret
{
	NOTHING,
	NEW_RED_CHILD,
	NEW_RED_GRAND_CHILD
};

struct s_rbtree
{
	struct s_rbtree	*left;
	struct s_rbtree	*right;
	enum e_color	color;
};

#endif
