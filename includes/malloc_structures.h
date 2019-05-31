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

/*
** The doubly linked lists shall hold page which have at least one free node
** (for their category)
** The lists shall be sorted in ascending order by total free space available,
** in order to have the most filled up pages at the top.
**
** Once they are totally filled, they should be removed from the list and stored
** elsewhere.
*/

struct	s_alloc_categorie
{
	struct s_rbtree			*page_tree;
	struct s_double_list	*tinies;
	struct s_double_list	*smalls;
};

extern struct s_alloc_categorie g_alloc_zones;

#endif
