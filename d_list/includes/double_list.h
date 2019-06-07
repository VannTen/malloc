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

#ifndef DOUBLE_LIST_H
# define DOUBLE_LIST_H
# include <stddef.h>

struct	s_double_list {
	struct s_double_list	*previous;
	struct s_double_list	*next;
};

/*
** Insertion
*/

void	d_list_insert_front(
		struct s_double_list **origin,
		struct s_double_list *new_node);
void	d_list_insert_back(
		struct s_double_list **origin,
		struct s_double_list *new_node);

/*
** Find
*/

void	*d_list_find(
		struct s_double_list *list,
		void *(*match)(struct s_double_list const *, void const*), void const *data);
void	*d_list_find_back(
		struct s_double_list *list,
		void *(*match)(struct s_double_list const *, void const*), void const *data);


/*
** Delete
*/

void	d_list_remove(struct s_double_list *list);
void	d_list_init(struct s_double_list *list);

/*
** Count
*/

size_t	d_list_elem_count(struct s_double_list const *list);

#endif
