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
#include "constants.h"
#include "free_node.h"
#include "itoa_tools.h"
#include "string.h"
#include <assert.h>
#include <unistd.h>

static char const	*select_type_string(struct s_alloc_zone const *zone)
{
	char const					*type_string;

	if (is_large(zone))
		type_string = "LARGE";
	else if (is_tiny(zone))
		type_string = "TINY";
	else if (is_small(zone))
		type_string = "SMALL";
	else
		type_string = "ERROR";
	return (type_string);
}

static size_t		write_pointer(void const *ptr, char *string)
{
	size_t len;

	string[0] = '0';
	string[1] = 'x';
	len = itoa_len_unsigned((uintptr_t)ptr, 16) + 1;
	itoa_write_unsigned(string + len,
			(uintptr_t)ptr, 16, HEXADECIMAL_DIGITS);
	return (len + 1);
}

static size_t		write_node(
		struct s_free_node const *node,
		char *const string)
{
	size_t string_index;

	string_index = write_pointer(get_public_address(node), string);
	ft_strcpy(string + string_index, " - ");
	string_index += sizeof(" - ") - 1;
	string_index += write_pointer(end_of_node(node), string + string_index);
	ft_strcpy(string + string_index, " : ");
	string_index += sizeof(" : ") - 1;
	string_index += itoa_len_unsigned(node_size(node), 10) - 1;
	itoa_write_unsigned(string + string_index, node_size(node),
			10, DECIMAL_DIGITS);
	ft_strcpy(string + string_index + 1, " octets\n");
	return (string_index + sizeof(" octets\n"));
}

static void			print_page_infos(struct s_alloc_zone const *const zone)
{
	char	buf[100];

	ft_strcpy(buf, select_type_string(zone));
	ft_strcpy(buf + ft_strlen(buf), " : ");
	buf[ft_strlen(buf) + write_pointer(zone, buf + ft_strlen(buf))] = '\0';
	ft_strcpy(buf + ft_strlen(buf), "\n");
	write(STDOUT_FILENO, buf, ft_strlen(buf));
}

size_t				alloc_zone_print(struct s_alloc_zone const *zone)
{
	size_t						size;
	size_t						size_allocated;
	struct s_free_node const	*node;
	char						buf[255];

	assert(zone != NULL);
	node = get_first_node(zone);
	size_allocated = 0;
	print_page_infos(zone);
	while (1)
	{
		if (!node->free)
		{
			size = write_node(node, buf);
			buf[size] = '\0';
			write(STDOUT_FILENO, buf, size);
			size_allocated += node_size(node);
		}
		if (is_last_node(node))
			break ;
		node = next_node(node);
	}
	return (size_allocated);
}
