/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_zone.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 13:11:17 by                   #+#    #+#             */
/*   Updated: 2019/02/25 13:11:17 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLOC_ZONE_H
# define ALLOC_ZONE_H
# include "free_node.h"
# include "bool.h"
# include "rb_tree.h"
# include "list.h"
# include <stddef.h>

struct s_alloc_zone {

	struct s_rbtree	tree_node;
	size_t			size;
	size_t			biggest_free_size;
	struct s_list	list;
};

size_t				round_up_to_multiple(size_t n, size_t log_2);
struct s_alloc_zone	*create_zone(size_t	size);
t_bool		assert_create_zone(struct s_alloc_zone const *);

/*
** Get (const)
*/

struct s_free_node	*get_first_node(struct s_alloc_zone const * zone);
size_t				nb_free_node(struct s_alloc_zone const *);
size_t				nb_node(struct s_alloc_zone const *);
void				*end_of_zone(struct s_alloc_zone const *);
struct s_alloc_zone const *page_from_list_node(struct s_list const *list_node);
int					alloc_zone_cmp(void const *, void const *);
size_t				page_size_category(struct s_alloc_zone const *page);
int					address_exists_in_page(
		void const *address,
		struct s_alloc_zone const *page);
size_t				alloc_zone_print(struct s_alloc_zone const *);

/*
** Get
*/

struct s_free_node const	*get_first_fit(struct s_alloc_zone *, size_t);

#endif
