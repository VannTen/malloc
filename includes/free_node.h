/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_node.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 13:03:16 by                   #+#    #+#             */
/*   Updated: 2019/02/25 13:03:16 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_NODE_H
# define FREE_NODE_H
# include <stddef.h>
# include "bool.h"
# define LOG_2_ALIGN 4
# define MIN_ALLOC_SPACE sizeof (void*)

struct s_free_node	{

	struct s_free_node	*next;
	t_bool				free;
};


/*
** Get (const)
*/

void const	*get_public_address(struct s_free_node const *);
size_t	node_size(struct s_free_node const *);
t_bool		is_last_node(struct s_free_node const *);

/*
** Modify
*/

void const	*publish_address(struct s_free_node *);
void		free_node(void *);
void		free_defrag(void *);

#endif
