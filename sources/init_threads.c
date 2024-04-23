/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:56:35 by deydoux           #+#    #+#             */
/*   Updated: 2024/04/23 14:05:22 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	init_thread(t_philo *philo)
{
	return (pthread_create(&philo->thread, NULL, (void *)routine, philo) != 0);
}

bool	init_threads(t_table *table)
{
	bool	error;
	size_t	i;

	error = false;
	i = 0;
	pthread_mutex_lock(&table->common.mutex.data);
	while (!error && i < table->n_philo)
		error = init_thread(&table->philos[i++]);
	table->common.ready = !error;
	table->common.start_time = get_ms_time();
	if (!table->common.ready)
		ft_putstr_fd(ERR_INIT_THREADS, STDERR_FILENO);
	pthread_mutex_unlock(&table->common.mutex.data);
	return (error);
}
