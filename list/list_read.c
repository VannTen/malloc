/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 13:46:37 by                   #+#    #+#             */
/*   Updated: 2019/05/12 13:46:37 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stddef.h>

struct s_list	*list_search(struct s_list *list, void const *data,
		int (*match)(void const *data, struct s_list const *node))
{
	while (list != NULL && !match(data, list))
		list = list->next;
	return (list);
}
