/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:18:39 by deydoux           #+#    #+#             */
/*   Updated: 2024/04/30 14:06:47 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	destroy_mutex(t_safe_mutex mutex)
{
	if (mutex.initialized)
		pthread_mutex_destroy(&mutex.data);
}

static void	destroy_philo(t_philo philo)
{
	if (philo.thread.initialized)
		pthread_join(philo.thread.data, NULL);
	destroy_mutex(philo.right_fork.mutex);
}

static void	destroy_philos(t_table table)
{
	size_t	i;

	i = 0;
	if (table.philos)
		while (i < table.n_philo)
			destroy_philo(table.philos[i++]);
}

void	destroy_table(t_table table)
{
	destroy_mutex(table.common.mutex);
	destroy_philos(table);
	free(table.philos);
}
