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

#include "malloc.h"
#include "malloc_structures.h"
#include "alloc_zone.h"
#include "rb_tree.h"

static int	s_bad_page(
		struct s_rbtree const *const page,
		void const *data)
{
	(void)data;
	return (bad_page((struct s_alloc_zone const*)page));
}

int			malloc_pages_in_good_state(void)
{
	return (btree_preorder_search(
				g_alloc_zones.page_tree, NULL, s_bad_page) == NULL);
}
