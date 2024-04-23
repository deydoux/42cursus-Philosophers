/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:18:39 by deydoux           #+#    #+#             */
/*   Updated: 2024/04/23 13:59:50 by deydoux          ###   ########.fr       */
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
	pthread_join(philo.thread, NULL);
	destroy_mutex(philo.right_fork);
}

static void	destroy_philos(t_table table)
{
	size_t	i;

	i = 0;
	while (i < table.n_philo)
		destroy_philo(table.philos[i++]);
}

void	destroy_table(t_table table)
{
	destroy_mutex(table.common.mutex);
	destroy_philos(table);
	free(table.philos);
}
