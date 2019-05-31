/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_list_find.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 13:48:00 by                   #+#    #+#             */
/*   Updated: 2019/05/31 13:48:00 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_list.h"

void	*d_list_find(struct s_double_list *const first_node,
		void *(*match)(struct s_double_list *))
{
	struct s_double_list	*node;
	void					*result;

	node = first_node;
	while (1)
	{
		result = match(node);
		node = node->next;
		if (node == first_node)
			break ;
	}
	return (result);
}

void	*d_list_find_back(struct s_double_list *const first_node,
		void *(*match)(struct s_double_list *))
{
	struct s_double_list	*node;
	void					*result;

	node = first_node;
	while (1)
	{
		result = match(node);
		node = node->previous;
		if (node == first_node)
			break ;
	}
	return (result);
}

