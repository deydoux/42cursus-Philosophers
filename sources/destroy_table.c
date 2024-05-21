/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:18:39 by deydoux           #+#    #+#             */
/*   Updated: 2024/05/21 17:54:28 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	destroy_mutex(t_safe_mutex *mutex)
{
	if (mutex->initialized)
		pthread_mutex_destroy(&mutex->data);
}

static void	destroy_thread(t_safe_thread thread)
{
	if (thread.initialized)
		pthread_join(thread.data, NULL);
}

static void	destroy_philo(t_philo *philo)
{
	destroy_thread(philo->thread);
	destroy_mutex(&philo->right_fork.change_mutex);
	destroy_mutex(&philo->right_fork.mutex);
}

static void	destroy_philos(t_table *table)
{
	size_t	i;

	i = 0;
	if (table->philos)
		while (i < table->n_philo)
			destroy_philo(&table->philos[i++]);
}

void	destroy_table(t_table *table)
{
	destroy_philos(table);
	free(table->philos);
	destroy_mutex(&table->common.mutex);
}
