/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock_malloc_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 13:00:23 by                   #+#    #+#             */
/*   Updated: 2019/06/13 13:00:23 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc_structures.h"

int	malloc_write_lock(void)
{
	return (pthread_rwlock_wrlock(&g_alloc_zones.lock));
}

int	malloc_read_lock(void)
{
	return (pthread_rwlock_rdlock(&g_alloc_zones.lock));
}

int	malloc_unlock(void)
{
	return (pthread_rwlock_unlock(&g_alloc_zones.lock));
}
