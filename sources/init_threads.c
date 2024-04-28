/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:56:35 by deydoux           #+#    #+#             */
/*   Updated: 2024/04/28 21:30:44 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	init_thread(t_philo *philo)
{
	philo->thread.initialized = !pthread_create(&philo->thread.data, NULL,
			(void *)routine, philo);
	if (!philo->thread.initialized)
	{
		ft_putstr_fd(ERR_INIT_THREADS, STDERR_FILENO);
		return (true);
	}
	return (false);
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
	table->common.kill = error;
	table->common.start_time = get_ms_time();
	pthread_mutex_unlock(&table->common.mutex.data);
	return (error);
}
