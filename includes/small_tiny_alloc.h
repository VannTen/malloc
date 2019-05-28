/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_tiny_alloc.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 16:34:05 by                   #+#    #+#             */
/*   Updated: 2019/05/28 16:34:05 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SMALL_TINY_ALLOC_H
# define SMALL_TINY_ALLOC_H
# include <stddef.h>

struct s_free_node const	*alloc_tiny_small(size_t const size);

#endif
