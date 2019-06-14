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
