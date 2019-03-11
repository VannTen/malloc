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

struct s_free_node	{

	struct s_free_node	*next;
	t_bool				free;
};



#endif
