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

#ifndef RB_TREE_H
# define RB_TREE_H
# include <stddef.h>

enum					e_color
{
	RED,
	BLACK
};

enum					e_tree_insert_ret
{
	NOTHING,
	NEW_RED_CHILD,
	NEW_RED_GRAND_CHILD
};

enum					e_tree_state
{
	GOOD,
	TREE_HAS_ONE_BLACK_LESS
};

struct					s_rbtree
{
	struct s_rbtree	*children[2];
	enum e_color	color;
};

enum
{
	LEFT,
	RIGHT
};

/*
**Btree operations (operates on btree part of red black trees)
*/

struct s_rbtree const	*btree_search(struct s_rbtree const *node,
		void const *data,
		int (*cmp)(void const *node, void const *data));
void					rbtree_inorder_traversal(
		struct s_rbtree const *tree,
		void (*f)(void const *node, void *extern_context),
		void *extern_context);
struct s_rbtree const	*btree_preorder_search(struct s_rbtree const *node,
		void const *ref_data,
		int (*match)(struct s_rbtree const *node, void const *ref_data));
int						tree_is_inorder(struct s_rbtree const *tree);
void					left_rotate(struct s_rbtree **root);
void					right_rotate(struct s_rbtree **root);
void					rotate(struct s_rbtree **parent, int side);

/*
**Red Black Trees operations (specific)
*/

void					rbtree_insert(
	struct s_rbtree **tree,
	struct s_rbtree *new_node,
	int (*diff)(void const *ref, void const *inserted));
void					rbtree_init_node(struct s_rbtree *node);
void					*rbtree_remove(struct s_rbtree **tree,
		void const *criterion,
		int (*diff)(void const*, void const*));

/*
**Red Black trees properties checks
*/

size_t					black_depth(struct s_rbtree const *tree);
size_t					max_depth(struct s_rbtree const *t);
size_t					min_depth(struct s_rbtree const *t);
int						is_valid_rb_tree(struct s_rbtree const *t);

/*
**Tree metadat
*/

size_t					rbtree_node_count(struct s_rbtree const *t);

/*
**Implementation, not part of interface
*/

/*
**Tree balancing
*/

enum e_tree_state		balance_subtree(
		struct s_rbtree **const tree,
		int side,
		enum e_tree_state subtree_state);

/*
**Helpers
*/

enum e_color			color(struct s_rbtree const *n);

/*
**Debug
*/

void					print_tree(struct s_rbtree const *t);
struct s_rbtree			*rbtree_from_sequential(
		void *first,
		void *(*next)(void *),
		int (*cmp)(void const *, void const *),
		void *end_address);

#endif
