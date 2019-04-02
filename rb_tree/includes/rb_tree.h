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
# include <stddef.h>

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

/*
** Btree operations (operates on btree part of red black trees)
*/

struct s_rbtree const	*btree_search(struct s_rbtree const *node,
		void *data,
		int (*cmp)(void const*, void const*));
void	rbtree_inorder_traversal(
		struct s_rbtree const * tree,
		void (*f)(void const * node, void *extern_context),
		void *extern_context);
void	left_rotate(struct s_rbtree ** root);
void	right_rotate(struct s_rbtree ** root);
void	rotate(struct s_rbtree **parent, struct s_rbtree *child);

/*
** Red Black Trees operations (specific)
*/

void	rbtree_insert(
	struct s_rbtree ** tree,
	struct s_rbtree *new_node,
	int (*diff)(void const * ref, void const * inserted));
void	rbtree_init_node(struct s_rbtree *node);

/*
** Red Black trees properties checks
*/

size_t	black_depth(struct s_rbtree const * tree);
size_t	max_depth(struct s_rbtree const *);
size_t	min_depth(struct s_rbtree const *);

#endif
