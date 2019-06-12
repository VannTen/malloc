/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intern_alloc_helpers.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 14:09:34 by                   #+#    #+#             */
/*   Updated: 2019/06/12 14:09:34 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_ALLOC_HELPERS_H
# define INTERN_ALLOC_HELPERS_H
# include <stddef.h>

void	*realloc_intern(void *ptr, size_t new_size, int is_reallocf);

#endif
