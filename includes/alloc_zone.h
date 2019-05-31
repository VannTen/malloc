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

struct						s_alloc_zone {

	struct s_rbtree			tree_node;
	size_t					size;
	size_t					total_free_size;
	size_t					nb_node;
	size_t					nb_free_node;
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
size_t						page_size_category(struct s_alloc_zone const *page);
int							address_exists_in_page(
						void const *address,
						struct s_alloc_zone const *page);
size_t						alloc_zone_print(struct s_alloc_zone const *z);

/*
** Get
*/

struct s_free_node const	*get_first_fit(struct s_alloc_zone *z, size_t s);

#endif
