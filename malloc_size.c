/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 13:49:17 by                   #+#    #+#             */
/*   Updated: 2019/06/13 13:49:17 by                  ###   ########.fr       */
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
