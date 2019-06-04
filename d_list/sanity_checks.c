/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sanity_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 13:14:59 by                   #+#    #+#             */
/*   Updated: 2019/06/04 13:14:59 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double_list.h"
#include "double_list_debug.h"

int	d_list_sanity_checks(struct s_double_list const *const list)
{
	return ((list->previous == list
			&& list->next == list)
			|| (list->previous != list
				&& list->next != list));
}
