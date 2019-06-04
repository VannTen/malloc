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
#include <stddef.h>

void	*d_list_find(struct s_double_list *const first_node,
		void *(*match)(struct s_double_list const *, void const *data),
		void const *data)
{
	struct s_double_list	*node;
	void					*result;

	if (first_node == NULL)
		return (NULL);
	node = first_node;
	while (1)
	{
		result = match(node, data);
		node = node->next;
		if (node == first_node || result != NULL)
			break ;
	}
	return (result);
}

void	*d_list_find_back(struct s_double_list *const first_node,
		void *(*match)(struct s_double_list const *, void const *data),
		void const *data)
{
	struct s_double_list	*node;
	void					*result;

	if (first_node == NULL)
		return (NULL);
	node = first_node;
	while (1)
	{
		result = match(node, data);
		node = node->previous;
		if (node == first_node || result != NULL)
			break ;
	}
	return (result);
}

