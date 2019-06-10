/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_sanity_checks.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 15:59:22 by                   #+#    #+#             */
/*   Updated: 2019/06/10 15:59:22 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include "malloc_structures.h"
#include "alloc_zone.h"
#include "rb_tree.h"

static int	s_bad_page(
		struct s_rbtree const *const page,
		void const *data __attribute__((unused)))
{
	return (bad_page((struct s_alloc_zone const*)page));
}

int	malloc_pages_in_good_state()
{
	return (btree_preorder_search(
				g_alloc_zones.page_tree, NULL, s_bad_page) == NULL);
}
