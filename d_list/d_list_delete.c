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

void	d_list_remove(struct s_double_list *list)
{
	assert(list != NULL);
	list->next->previous = list->previous;
	list->previous->next = list->next;
	d_list_init(list);
	assert(d_list_sanity_checks(list));
}
