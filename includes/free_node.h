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

#ifndef FREE_NODE_H
# define FREE_NODE_H
# include <stddef.h>
# include "bool.h"
# define LOG_2_ALIGN 4

struct				s_free_node	{

	int		next_offset;
	t_bool	free:1;
};

/*
** Get (const)
*/

void const			*get_public_address(struct s_free_node const *n);
struct s_free_node	*get_node_from_address(void *address);
void const			*end_of_node(struct s_free_node const *n);
size_t				node_size(struct s_free_node const *n);
t_bool				is_last_node(struct s_free_node const *n);
struct s_free_node	*next_node(struct s_free_node const *node);
int					address_is_taken(void const *address);

/*
** Modify
*/

void				free_node(void *address);
void				merge_with_next_nodes(struct s_free_node *node);
struct s_alloc_zone	*free_defrag(void *address);

#endif
