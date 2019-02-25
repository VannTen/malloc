/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_zone.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 13:11:17 by                   #+#    #+#             */
/*   Updated: 2019/02/25 13:11:17 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLOC_ZONE_H
# define ALLOC_ZONE_H

struct s_alloc_zone {

	enum {TINY, SMALL}	type;
	struct	s_free_node	first_node; // will be a sentinel.
}

#endif
