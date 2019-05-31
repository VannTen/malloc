/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_list_delete.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 13:45:42 by                   #+#    #+#             */
/*   Updated: 2019/05/31 13:45:42 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_list.h"
#include <stddef.h>
#include <assert.h>

void	d_list_remove(struct s_double_list *list)
{
	assert(list != NULL);
	list->next->previous = list->previous;
	list->previous->next = list->next;
	d_list_init(list);
}
