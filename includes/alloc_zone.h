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
# include <stddef.h>

struct s_alloc_zone {

//	t_rb_node	node; // TODO
	size_t		biggest_size;
};

size_t				round_up_to_multiple(size_t n, size_t log_2);
struct s_alloc_zone	*create_zone(size_t	size);
t_bool		assert_create_zone(struct s_alloc_zone const *);

/*
** Get (const)
*/

struct s_free_node	*get_first_node(struct s_alloc_zone const * zone);

/*
** Get
*/

void				*get_first_fit(struct s_alloc_zone *, size_t);

#endif
