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
