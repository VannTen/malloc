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

#include "alloc_zone.h"
#include "constants.h"

int	main(void)
{
	struct s_alloc_zone *page;

	page = create_zone(tiny_page_size());
	get_first_fit(page, 12);
	get_first_fit(page, 12);
	get_first_fit(page, 12);
	get_first_fit(page, 14);
	get_first_fit(page, 12);
	alloc_zone_print(page);

	return (0);
}
