/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   page_size_constants.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 14:21:07 by                   #+#    #+#             */
/*   Updated: 2019/04/29 14:21:07 by                  ###   ########.fr       */
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
