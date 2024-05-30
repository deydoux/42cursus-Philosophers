/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:18:39 by deydoux           #+#    #+#             */
/*   Updated: 2024/05/30 15:52:33 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	destroy_thread(t_safe_thread thread)
{
	if (thread.initialized)
		pthread_join(thread.data, NULL);
}

static void	destroy_semaphore(sem_t *sem)
{
	if (sem)
		sem_close(sem);
}

static void	destroy_philos(t_philo *philos, size_t n)
{
	size_t	i;

	if (!philos)
		return ;
	i = 0;
	while (i < n)
		destroy_thread(philos[i++].thread);
	free(philos);
}

void	destroy_table(t_table *table)
{
	destroy_philos(table->philos, table->n_philo);
	destroy_semaphore(table->common.die_time_sem);
	destroy_semaphore(table->common.forks_sem);
	destroy_semaphore(table->common.lock_sem);
}
