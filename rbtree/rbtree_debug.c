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

#include <stdio.h>
#include "rb_tree.h"
#include "rb_tree_test.h"

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

static void	print_subtree_content(struct s_rbtree const *tree, int offset)
{
	int const child_offset = offset + 16;

	if (tree != NULL)
	{
		print_subtree_content(tree->children[RIGHT], child_offset);
		printf("%*d\n", offset, ((struct s_test_node*)tree)->value);
		print_subtree_content(tree->children[LEFT], child_offset);
	}
}


void	print_tree(struct s_rbtree const *tree)
{
	print_subtree(tree, 0);
}

void	print_tree_content(struct s_rbtree const *tree)
{
	print_subtree_content(tree, 0);
}
