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
#include "string.h"
#include "itoa_tools.h"
#include <unistd.h>

static void	_print_page_summary(void const *page,
		void *context)
{
	*(size_t*)context += alloc_zone_print(page);
}

void	show_alloc_mem(void)
{
	size_t				total_size;
	char				buffer[100];
	size_t				index;
	static const char	*strings[] = {"Total : ", " octets\n"};

	total_size = 0;
	rbtree_inorder_traversal(g_alloc_zones.page_tree,
			_print_page_summary, &total_size);
	ft_strcpy(buffer, strings[0]);
	index = ft_strlen(strings[0]);
	index += itoa_len_unsigned(total_size, 10) - 1;
	itoa_write_unsigned(buffer + index, total_size, 10, DECIMAL_DIGITS);
	ft_strcpy(buffer + index, strings[1]);
	index += ft_strlen(strings[1]);
	write(STDOUT_FILENO, buffer, index);
}
