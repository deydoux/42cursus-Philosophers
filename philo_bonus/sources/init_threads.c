/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:56:35 by deydoux           #+#    #+#             */
/*   Updated: 2024/05/24 20:57:01 by deydoux          ###   ########.fr       */
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
	size_t	i;

	i = 0;
	while (!table->common.exit && i < table->n_philo)
		table->common.exit = init_thread(&table->philos[i++]);
	table->common.start_time = get_ms_time();
	sem_post(table->common.lock_sem);
	return (table->common.exit);
}
