/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_safety.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 13:45:00 by                   #+#    #+#             */
/*   Updated: 2019/06/13 13:45:00 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memutils.h"
#include <pthread.h>
#include <stdlib.h>
#define ARRAY_SIZE 50000
#define NUMBER_OF_THREADS 50
#define MAX_ALLOC 1500

void	*alloc_and_write(void *data)
{
	void **const	array = data;
	size_t			index;
	size_t			size;

	index = 0;
	while (index < ARRAY_SIZE / NUMBER_OF_THREADS)
	{
		size = rand() % MAX_ALLOC;
		array[index] = malloc(size);
		ft_memset(array[index], '%', size);
		index++;
	}
	return (array);
}

void	*realloc_and_write(void *data)
{
	void **const	array = data;
	size_t			index;
	size_t			size;

	index = 0;
	while (index < ARRAY_SIZE / NUMBER_OF_THREADS)
	{
		size = rand() % MAX_ALLOC;
		array[index] = realloc(array[index], size);
		ft_memset(array[index], '%', size);
		index++;
	}
	return (array);
}

void	*free_stuff(void *data)
{
	void **const	array = data;
	size_t			index;

	index = 0;
	while (index < ARRAY_SIZE / NUMBER_OF_THREADS)
	{
		free(array[index]);
		array[index] = NULL;
		index++;
	}
	return (array);
}

void	join_threads(pthread_t *threads)
{
	size_t	thread_joined;
	void	*placeholder_for_threads;

	thread_joined = 0;
	while (thread_joined < NUMBER_OF_THREADS)
	{
		pthread_join(threads[thread_joined], &placeholder_for_threads);
		thread_joined++;
	}
}

int		main(void)
{
	void		*array[ARRAY_SIZE];
	size_t		thread_created;
	pthread_t	thread[NUMBER_OF_THREADS];

	thread_created = 0;
	while (thread_created < NUMBER_OF_THREADS)
	{
		pthread_create(thread + thread_created, NULL, alloc_and_write,
				array + (ARRAY_SIZE / NUMBER_OF_THREADS) * thread_created);
		thread_created++;
	}
	join_threads(thread);
	while (thread_created < NUMBER_OF_THREADS)
	{
		pthread_create(thread + thread_created, NULL, realloc_and_write,
				array + (ARRAY_SIZE / NUMBER_OF_THREADS) * thread_created);
		thread_created++;
	}
	join_threads(thread);
	while (thread_created < NUMBER_OF_THREADS)
	{
		pthread_create(thread + thread_created, NULL, free_stuff,
				array + (ARRAY_SIZE / NUMBER_OF_THREADS) * thread_created);
		thread_created++;
	}
}
