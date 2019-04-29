/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:26:50 by                   #+#    #+#             */
/*   Updated: 2019/03/13 17:26:50 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H
# include <stddef.h>

/*
** Implementation choices constants
**
** The allocation size categories are defined in terms of alignment multiple
** The minimal possible size is ALIGNMENT - sizeof(metadata struct);
** Any size in tiny or small will be of the form
** ALIGMENT x N - sizeof(metadata struct)
*/

# define ALIGNMENT 16
# define TINY_MAX 2
# define SMALL_MAX 16
# define MIN_FREE_NODE_PER_PAGE 100

/*
** Computed constants implemented as functions
*/

size_t	offset_zone_start_first_address( void );
size_t	offset_zone_start_first_free_node( void );
size_t	ft_pow(size_t n, size_t pow);
size_t	tiny_size_limit( void );
size_t	small_upper_limit( void );
size_t	tiny_page_size( void );
size_t	small_page_size( void );

#endif
