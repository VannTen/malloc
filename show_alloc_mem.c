/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 16:43:34 by                   #+#    #+#             */
/*   Updated: 2019/05/27 16:43:34 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alloc_zone.h"
#include "malloc_structures.h"
#include "rb_tree.h"

static void	_print_page_summary(void const *page,
		void *__attribute__((unused))context)
{
	alloc_zone_print(page);
}

void	show_alloc_mem(void)
{
	rbtree_inorder_traversal(g_alloc_zones.page_tree,
			_print_page_summary, NULL);
}
