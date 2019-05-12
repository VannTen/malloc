/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_modify.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 13:38:20 by                   #+#    #+#             */
/*   Updated: 2019/05/12 13:38:20 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stddef.h>

void			list_add_end(struct s_list **list, struct s_list *node)
{
	while (*list != NULL)
		list = &(*list)->next;
	*list = node;
}

void			list_add_start(struct s_list **list, struct s_list *node)
{
	node->next = *list;
	*list = node;
}

struct s_list	*list_remove_if(struct s_list **list, void const *data,
		int (*to_remove)(void const *data, struct s_list const *node))
{
	struct s_list *removed;

	while (*list != NULL && !to_remove(data, *list))
		list = &(*list)->next;
	removed = *list;
	if (removed != NULL)
		*list = removed->next;
	return (removed);
}
