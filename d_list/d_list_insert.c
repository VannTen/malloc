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
#include "double_list_debug.h"
#include <stddef.h>
#include <assert.h>

static void	d_list_insert_at(
		struct s_double_list *origin,
		struct s_double_list *new_node)
{
	new_node->next = origin;
	new_node->previous = origin->previous;
	new_node->next->previous = new_node;
	new_node->previous->next = new_node;
	origin->previous = new_node;
	assert(d_list_sanity_checks(origin));
	assert(d_list_sanity_checks(new_node));
}

void	d_list_insert_front(
		struct s_double_list **origin,
		struct s_double_list *new_node)
{
	if (*origin != NULL)
	{
		d_list_insert_at(*origin, new_node);
		*origin = new_node;
	}
	else
	{
		*origin = new_node;
		new_node->previous = new_node;
		new_node->next = new_node;
	}
}

void	d_list_insert_back(
		struct s_double_list **origin,
		struct s_double_list *new_node)
{
	if (*origin != NULL)
		d_list_insert_at(*origin, new_node);
	else
	{
		*origin = new_node;
		new_node->previous = new_node;
		new_node->next = new_node;
	}
}
