/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 17:26:35 by                   #+#    #+#             */
/*   Updated: 2019/05/10 17:26:35 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

struct s_list
{
	struct s_list	*next;
};

struct s_list	*list_remove_if(
		struct s_list **list,
		void const *data,
		int	(*to_remove)(void const *data, struct s_list const *node));
void			list_add_start(struct s_list **list, struct s_list *new_node);
void			list_add_end(struct s_list **list, struct s_list *new_node);
struct s_list	*list_search(
		struct s_list *list,
		void const *data,
		int	(*to_remove)(void const *data, struct s_list const *node));

#endif
