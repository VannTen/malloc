/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree_debug.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:19:56 by                   #+#    #+#             */
/*   Updated: 2019/04/11 18:19:56 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "rb_tree.h"

static void	print_subtree(struct s_rbtree const *tree, int offset)
{
	int const child_offset = offset + 8;

	if (tree != NULL)
	{
		print_subtree(tree->children[RIGHT], child_offset);
		printf("%*c\n", offset, tree->color == RED ? 'R' : 'B');
		print_subtree(tree->children[LEFT], child_offset);
	}
	else
		printf("%*c\n", offset, 'L');
}

void	print_tree(struct s_rbtree const *tree)
{
	print_subtree(tree, 0);
}
