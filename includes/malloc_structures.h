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
	s_alloc_zone	*categories[3];
	s_alloc_zone	*tinys[TINY_MAX];
	s_alloc_zone	*small[SMALL_MAX - TINY_MAX];
};

extern struct s_alloc_categorie alloc_trees;


#endif
