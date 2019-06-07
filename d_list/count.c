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

size_t	d_list_elem_count(struct s_double_list const *const list)
{
	struct s_double_list const *node;
	size_t						count;

	if (list == NULL)
		return (0);
	count = 1;
	node = list->next;
	while (node != list)
	{
		count++;
		node = node->next;
	}
	return (count);
}
