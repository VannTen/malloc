/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_first_fit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 13:30:59 by                   #+#    #+#             */
/*   Updated: 2019/02/25 13:30:59 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	carve_new_node(
		struct s_free_node *origin,
		size_t size)
{
	struct s_free_node	*new_node;

	size_of_rest = origin->size - size;
	new_node = (char*)get_public_address(origin) + size;
	new_node->size = origin->size - size; // TODO: get s_free_node size + padding.
	new_node->next = origin->next;
	origin->size = size;
	origin->next = new_node;
}

t_bool	node_fits(struct s_free_node *node, size_t size)
{
	if (node->size < size)
		return (false);
	else if (node->size > size)
		carve_new_node(node, size);
	return (true);
}

void	*get_first_fit(struct s_alloc_zone *zone, size_t size_required)
{
	struct s_free_node * const first_node = get_first_node(zone);
	struct s_free_node * current_node;

	current_node = first_node;
	while (node != NULL && node_fits(node, size_required))
		node = node->next;

	return (node != NULL ? get_public_address(node) : NULL);
}
