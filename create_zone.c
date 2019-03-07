/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_zone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 13:51:47 by                   #+#    #+#             */
/*   Updated: 2019/02/25 13:51:47 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/mman.h>

/*
** - allocate a mapping
** - compute the first aligned address in the mapping that will allow to put a
** s_alloc_zone + a s_free_node before it.
** - write the first free node.
**
**
** Assumptions : Address returned by mmap are aligned on the aligment used by
** align ( will probably be 16), so the offset between the address returned by
** mmap (the start of the mapping) and the first_client_address will always be
** the same.
*/

struct s_alloc_zone	*create_zone(size_t	size)
{
	void				*zone_start;
	struct s_alloc_zone	*alloc_zone;
	struct s_free_node	*first_node;
	void				*first_client_address;

	zone_start = mmap(NULL, size,
			PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE,
			VM_MAKE_TAG(get_zone_type(size)), 0);
	if (zone_start == MAP_FAILED)
		return (NULL);
	first_client_address = zone_start + sizeof *alloc_zone + sizeof *first_node;
	align(&first_client_address);
	first_node = first_client_address - sizeof *first_node;
	first_node->next = first_node;
	first_node->free = true;
	alloc_zone->biggest_size = compute_size(first_node, /* type */ );
	return (zone_start);
}
