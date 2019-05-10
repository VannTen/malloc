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
# include <stddef.h>

struct s_alloc_zone {

	struct s_rbtree	tree_node;
	size_t			size;
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

/*
** Get
*/

void const			*get_first_fit(struct s_alloc_zone *, size_t);

#endif
