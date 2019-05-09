/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 17:47:28 by                   #+#    #+#             */
/*   Updated: 2019/05/09 17:47:28 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	address_page_position(void const *address, void const *_page)
{
	struct s_alloc_zone const *page = _page;

	if ((uintptr_t)page > (uintptr_t)address)
		return (-1);
	else if ((uintptr_t)page + page->size > (uintptr_t)address)
		return (0);
	else
		return (-1);
}

static int	address_is_valid(void *address)
{
	return ((uintptr_t)address % ALIGNMENT == 0
			&& btree_search(g_alloc_zones.page_tree,
							address,
							address_page_position) != NULL);
}
