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

#ifndef MALLOC_STRUCTURES_H
# define MALLOC_STRUCTURES_H
# include "rb_tree.h"
# include "constants.h"

struct s_alloc_categorie
{
	struct s_rbtree		*page_tree;
	struct s_alloc_zone	*block_by_size[SMALL_MAX];
	struct s_list		*partially_used_pages[2];
};

extern struct s_alloc_categorie g_alloc_zones;


#endif
