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

struct s_alloc_zone	*create_zone(size_t	size)
{
	void				*zone_start;
	struct s_alloc_zone	*alloc_zone;
	struct s_free_node	*node;

	zone_start = mmap(NULL, size,
			PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE,
			VM_MAKE_TAG(get_zone_type(size)), 0);
	if (zone_start == MAP_FAILED)
		return (NULL);
	if (get_zone_type(size) != LARGE)
	{
		alloc_zone = zone_start;
		alloc_zone->type = get_zone_type(size);
		node = &alloc_zone->first_node;
		node->next = NULL;
		node->size = size - sizeof(struct s_alloc_zone);
	}
	return (zone_start);
}
