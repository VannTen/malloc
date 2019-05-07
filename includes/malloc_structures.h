/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_structures.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 12:55:11 by                   #+#    #+#             */
/*   Updated: 2019/04/27 12:55:11 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_STRUCTURES_H
# define MALLOC_STRUCTURES_H

struct s_alloc_categorie
{
	s_alloc_zone	*page_tree;
	s_alloc_zone	*block_by_size[SMALL_MAX];
	s_list			*partially_used_pages[2];
};

extern struct s_alloc_categorie g_alloc_zones;


#endif
