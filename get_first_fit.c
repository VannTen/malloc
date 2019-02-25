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

t_bool	node_fits(struct s_free_node const *node, size_t size)
{
	return (node->size >= size);
}

void	*get_first_fit(struct s_alloc_zone *zone, size_t size_required)
{
	struct s_free_node *node;

	node = zone->first_node;
	while (node != NULL && node_fits(node, size_required))
		node = node->next;

	return (node != NULL ? get_public_address(node) : NULL);
}
