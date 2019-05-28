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
#include <stddef.h>

static size_t	min(size_t val_1, size_t val_2)
{
	return (val_1 < val_2 ? val_1 : val_2);
}

static size_t	max(size_t val_1, size_t val_2)
{
	return (val_2 < val_1 ? val_1 : val_2);
}

size_t	black_depth(struct s_rbtree const * tree)
{
	size_t	left_depth;

	if (tree == NULL)
		return (1);
	else
	{
		left_depth = black_depth(tree->children[LEFT]);
		if (left_depth != black_depth(tree->children[RIGHT]) || left_depth == 0)
			return (0);
		else
			return (left_depth + (tree->color == BLACK ? 1 : 0));
	}
}

size_t	max_depth(struct s_rbtree const * tree)
{
	if (tree == NULL)
		return (1);
	else
		return (max(max_depth(tree->children[LEFT]), max_depth(tree->children[RIGHT])));
}

size_t	min_depth(struct s_rbtree const * tree)
{
	if (tree == NULL)
		return (1);
	else
		return (min(min_depth(tree->children[LEFT]), min_depth(tree->children[RIGHT])));
}
