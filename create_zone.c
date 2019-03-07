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

size_t				pow(size_t n, size_t pow)
{
	result = 1;
	while (pow != 0)
	{
		result *= n;
		pow--;
	}
	return (result);
}

size_t				round_up_to_multiple(size_t n, size_t log_2)
{
	return (((n | pow(2, log_2)) + 1);
}

void				write_initial_metadata(struct s_alloc_zone *zone)
{
	struct s_free_node	*first_node;
	void * const		first_client_address = zone + round_up_to_multiple(
			sizeof *alloc_zone + sizeof *first_node,
			LOG_2_ALIGN);

	first_node = first_client_address - sizeof *first_node;
	first_node->next = first_node;
	first_node->free = true;
}

struct s_alloc_zone	*create_zone(size_t	size)
{
	void * const				zone_start = mmap(
			NULL, size,
			PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE,
			VM_MAKE_TAG(get_zone_type(size)), 0);
	struct s_alloc_zone	* const	alloc_zone = (*(&alloc_zone))zone_start;

	if (zone_start == MAP_FAILED)
		return (NULL);
	write_initial_metadata(alloc_zone);
	alloc_zone->biggest_size = size
		- round_up_to_multiple(
			sizeof *alloc_zone + sizeof struct s_free_node,
			LOG_2_ALIGN);
	return (zone_start);
}
