/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_zone_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 11:14:00 by                   #+#    #+#             */
/*   Updated: 2019/05/27 11:14:00 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alloc_zone.h"
#include "constants.h"
#include "free_node.h"
#include "itoa_tools.h"
#include "string.h"
#include <assert.h>
#include <unistd.h>

char const		*select_type_string(struct s_alloc_zone const *zone)
{
	char const					*type_string;

	if (zone->biggest_free_size == LARGE_MAGIC_NUMBER)
		type_string = "LARGE";
	else if (zone->size == tiny_page_size())
		type_string = "TINY";
	else
		type_string = "SMALL";
	return (type_string);
}

static size_t	write_pointer(void const *ptr, char *string)
{
	size_t len;

	string[0] = '0';
	string[1] = 'x';
	len = itoa_len_unsigned((uintptr_t)ptr, 16);
	itoa_write_unsigned(string + len,
			(uintptr_t)ptr, 16, HEXADECIMAL_DIGITS);
	return (len);
}

static size_t	write_node(struct s_free_node const *node, char * const string)
{
	size_t string_index;

	string_index = 0;
	string_index += write_pointer(get_public_address(node), string );
	ft_strcpy(string + string_index, " - ");
	string_index += sizeof (" - ");
	string_index += write_pointer(end_of_node(node), string + string_index);
	ft_strcpy(string + string_index, " : ");
	string_index += sizeof (" : ");
	string_index += itoa_len_unsigned(node_size(node), 10);
	itoa_write_unsigned(string, node_size(node), 10, DECIMAL_DIGITS);
	ft_strcpy(string, " octets\n");
	return (string_index + sizeof(" octets\n"));
}

int	alloc_zone_print(struct s_alloc_zone const *zone)
{
	char const * const			 type_string  = select_type_string(zone);
	size_t						size;
	struct s_free_node const	*node;
	char						buf[255];

	assert(zone != NULL);
	node = get_first_node(zone);
	write(STDOUT_FILENO, type_string, ft_strlen(type_string));
	while (1)
	{
		if (!node->free)
		{
			size = write_node(node, buf);
			buf[size] = '\0';
			write(STDOUT_FILENO, buf, size);
		}
		if (is_last_node(node))
			break ;
		node = next_node(node);
	}
	return (0);
}
