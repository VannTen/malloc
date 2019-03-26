/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 16:30:00 by                   #+#    #+#             */
/*   Updated: 2019/03/25 16:30:00 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


static struct s_rbtree const *sibling(struct s_rbtree *cur_node, struct s_rbtree const * child)
{
	return (child == cur_node->left ? cur_node->left : cur_node->right);
}

static void grand_parent_become_red(struct s_rbtree *grand_parent)
{
	assert(grand_parent->left->color == RED && grand_parent->right->color == RED);
	grand_parent->color = RED;
	grand_parent->left->color = BLACK;
	grand_parent->right->color = BLACK;
}

static void insert_repair_rotation(
		struct s_rbtree **grand_parent,
		struct s_rbtree *child)
{
	t_bool const	left = (*grand_parent)->left == child;

	if (left && grand_parent->left->right->color == RED)
		rotate_left(&grand_parent->left);
	else if (!left && child->right->left->color == RED)
		rotate_right(&grand_parent->right);
	if (left)
	{
		rotate_right(grand_parent);
		(*grand_parent)->right->color = RED;
	}
	else
	{
		rotate_left(grand_parent);
		(*grand_parent)->left->color = RED;
	}
	(*grand_parent)->color = BLACK;
}

static enum e_insert_ret	repair_tree(
		struct s_rbtree **node,
		struct s_rbtree **child,
		enum e_insert_ret state)
{
	if (ret == NEW_RED_CHILD && node->color == RED)
		return (NEW_RED_GRAND_CHILD);
	else if (ret == RED_HAS_NEW_CHILD)
	{
		if (sibling(*tree, *child)->color == RED)
		{
			grand_parent_become_red(*node);
			return (NEW_RED_CHILD);
		}
		else
			insert_repair_rotation(node, *child);
	}

}

static void	insert(
	struct s_rbtree ** tree,
	struct s_rbtree *new_node,
	int (*cmp)(void const*, void const*))
{
	enum e_insert_return		ret;
	struct s_rbtree ** const	child;
		= cmp(*tree, new_node) < 0 ? &(*tree)->left : &(*tree)->right;

	if (*tree == NULL)
	{
		*tree = new_node;
		return (NEW_RED_CHILD);
	}
	else
		ret = insert(child, new_node, cmp);
	return (repair_tree(tree, child, ret));
}

void	rbtree_insert(
	struct s_rbtree ** tree,
	struct s_rbtree *new_node,
	int (*cmp)(void const*, void const*))
{
	if (NEW_RED_CHILD == insert_recurse(tree, new_node))
		(*tree)->color = BLACK;
}
