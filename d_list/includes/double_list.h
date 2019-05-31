/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 13:13:36 by                   #+#    #+#             */
/*   Updated: 2019/05/31 13:13:36 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLE_LIST_H
# define DOUBLE_LIST_H

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
		void *(*match)(struct s_double_list *));
void	*d_list_find_back(
		struct s_double_list *list,
		void *(*match)(struct s_double_list *));


/*
** Delete
*/

void	d_list_remove(struct s_double_list *list);
void	d_list_init(struct s_double_list *list);

#endif
