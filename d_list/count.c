/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 16:00:01 by                   #+#    #+#             */
/*   Updated: 2019/06/04 16:00:01 by                  ###   ########.fr       */
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
