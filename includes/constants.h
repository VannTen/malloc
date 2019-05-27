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
# include "free_node.h"
# include "alloc_zone.h"

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
# define LARGE_MAGIC_NUMBER (SMALL_MAX + 1)
# define MIN_FREE_NODE_PER_PAGE 100

/*
** Computed constants implemented as functions
*/

size_t	offset_zone_start_first_address( void );
size_t	offset_zone_start_first_free_node( void );
size_t	ft_pow(size_t n, size_t pow);
size_t	tiny_size_limit( void );
size_t	small_size_limit( void );
size_t	tiny_page_size( void );
size_t	small_page_size( void );
size_t	page_size(size_t align_multiple);
size_t	page_smallest_category(size_t current_biggest);

/*
** Shorthands functions for pointers offset computation
*/

struct s_alloc_zone const *get_page_from_first_node(struct s_free_node const *);

/*
** Translating size to size category and vice versa
*/

size_t	size_category_to_size(size_t size_category);
size_t	size_to_size_category(size_t size_category);
size_t	node_size_category(struct s_free_node const *node);
size_t	page_biggest_free_node_category(struct s_alloc_zone const *page);

#endif
