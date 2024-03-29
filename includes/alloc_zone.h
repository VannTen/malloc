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

#ifndef ALLOC_ZONE_H
# define ALLOC_ZONE_H
# include "bool.h"
# include "rb_tree.h"
# include "double_list.h"
# include <stddef.h>

enum						e_page_type {
	TINY,
	SMALL,
	LARGE
};

struct						s_alloc_zone {

	struct s_rbtree			tree_node;
	enum e_page_type		page_type;
	size_t					size;
	size_t					total_free_size;
	struct s_double_list	list;
};

size_t						round_up_to_multiple(size_t n, size_t log_2);
struct s_alloc_zone			*create_zone(size_t	size);
t_bool						assert_create_zone(struct s_alloc_zone const *z);

/*
** Get (const)
*/

struct s_free_node			*get_first_node(struct s_alloc_zone const *zone);
size_t						nb_free_node(struct s_alloc_zone const *z);
size_t						nb_node(struct s_alloc_zone const *z);
void						*end_of_zone(struct s_alloc_zone const *z);
struct s_alloc_zone			*page_from_list_node(
		struct s_double_list const *list_node);
int							alloc_zone_cmp(void const *lhs, void const *rhs);
int							address_exists_in_page(
						void const *address,
						struct s_alloc_zone const *page);
size_t						alloc_zone_print(struct s_alloc_zone const *z);

/*
** Get
*/

struct s_free_node			*get_first_fit(struct s_alloc_zone *z, size_t s);
int							is_large(struct s_alloc_zone const *z);
int							is_tiny(struct s_alloc_zone const *z);
int							is_small(struct s_alloc_zone const *z);

/*
** Space taken info
*/

size_t						alloc_zone_free_space(
		struct s_alloc_zone const *const zone);
size_t						alloc_zone_taken_space(
		struct s_alloc_zone const *const zone);
size_t						alloc_zone_all_space(
		struct s_alloc_zone const *const zone);

/*
** Sanity checks
*/

int							bad_page(struct s_alloc_zone const *page);

#endif
