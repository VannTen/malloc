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

#include "free_node.h"
#include "malloc_lock.h"
#include "constants.h"

size_t	malloc_good_size(size_t size)
{
	return (size_category_to_size(size_to_size_category(size)));
}

size_t	malloc_size(void const *addr)
{
	struct s_free_node const *const	node = get_node_from_address((void*)addr);
	size_t							size;

	malloc_read_lock();
	size = node_size(node);
	malloc_unlock();
	return (size);
}
