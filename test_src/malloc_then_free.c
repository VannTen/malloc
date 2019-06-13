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

#include <stdlib.h>
#include "malloc_structures.h"
#include "rb_tree.h"
#include "malloc.h"
#include <stdio.h>

int	main(void)
{
	int		i;
	char	*addr;

	i = 0;
	while (i < 1024)
	{
		addr = malloc(1024);
		addr[0] = 42;
		if (rbtree_node_count(g_alloc_zones.page_tree) > 1)
		{
			show_alloc_mem();
			printf("%zu pages on allocation %i\n",
					rbtree_node_count(g_alloc_zones.page_tree), i);
			return (1);
		}
		free(addr);
		i++;
	}
	return (0);
}
