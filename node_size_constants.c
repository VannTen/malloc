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

#include "constants.h"
#include "free_node.h"
#include <stddef.h>
#include <assert.h>

static size_t	size_limit(size_t align_multiple)
{
	return (align_multiple * ALIGNMENT - sizeof (struct s_free_node));
}

size_t			tiny_size_limit( void )
{
	return (size_limit(TINY_MAX));
}

size_t			small_size_limit( void )
{
	return (size_limit(SMALL_MAX));
}

size_t			page_smallest_category(size_t const page_current_biggest)
{
	assert(page_current_biggest <= SMALL_MAX);
	return (1 + (page_current_biggest <= TINY_MAX ? 0 : TINY_MAX));
}
