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
#include "free_node.h"
#include "constants.h"
#include <sys/mman.h>
#include <mach/vm_statistics.h>

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

size_t				round_up_to_multiple(size_t n, size_t multiple)
{
	return (n + multiple - 1 - (n + multiple - 1) % multiple);
}

void				write_initial_metadata(struct s_alloc_zone *zone)
{
	struct s_free_node	*const first_node = get_first_node(zone);

	first_node->next_offset = 0;
	first_node->free = TRUE;
}

static void			*vmem_allocation(size_t size)
{
	return (mmap(
			NULL, size,
			PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE,
			VM_MAKE_TAG(241), 0));
}

struct s_alloc_zone	*create_zone(size_t size)
{
	void *const					zone_start = vmem_allocation(size);
	struct s_alloc_zone	*const	alloc_zone = zone_start;

	if (zone_start == MAP_FAILED)
		return (NULL);
	write_initial_metadata(alloc_zone);
	alloc_zone->size = size;
	alloc_zone->total_free_size = node_size(get_first_node(alloc_zone));
	return (zone_start);
}
