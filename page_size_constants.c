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

#include "alloc_zone.h"
#include "free_node.h"
#include "constants.h"
#include <stddef.h>
#include <unistd.h>

size_t	page_size(size_t align_multiple)
{
	return (((align_multiple * ALIGNMENT * MIN_FREE_NODE_PER_PAGE
			+ sizeof (struct s_alloc_zone))
				/ getpagesize() + 1)
			* getpagesize());
}

size_t			tiny_page_size( void )
{
	return (page_size(TINY_MAX));
}

size_t			small_page_size( void )
{
	return (page_size(SMALL_MAX));
}
