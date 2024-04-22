/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:56:35 by deydoux           #+#    #+#             */
/*   Updated: 2024/04/22 15:07:30 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	init_thread(t_philo *philo)
{
	if (pthread_create(&philo->thread, NULL, (void *)routine, philo))
		return (true);
	pthread_detach(philo->thread);
	return (false);
}

bool	init_threads(t_table *table)
{
	size_t	i;

	i = 0;
	pthread_mutex_lock(&table->common.mutex.data);
	while (!table->common.ready && i < table->n_philo)
		table->common.ready = init_thread(&table->philos[i++]);
	table->common.ready = !table->common.ready;
	table->common.start_time = get_ms_time();
	if (!table->common.ready)
		ft_putstr_fd(ERR_INIT_THREADS, STDERR_FILENO);
	pthread_mutex_unlock(&table->common.mutex.data);
	return (!table->common.ready);
}
