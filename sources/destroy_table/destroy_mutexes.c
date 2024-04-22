/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mutexes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:20:57 by deydoux           #+#    #+#             */
/*   Updated: 2024/04/22 19:21:38 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "destroy_table.h"

static void	destroy_mutex(t_safe_mutex mutex)
{
	if (mutex.initialized)
		pthread_mutex_destroy(&mutex.data);
}

static void	destroy_fork_mutexes(t_table table)
{
	size_t	i;

	i = 0;
	while (i < table.n_philo)
		destroy_mutex(table.philos[i++].right_fork);
}

void	destroy_mutexes(t_table table)
{
	destroy_mutex(table.common.mutex);
	destroy_fork_mutexes(table);
}
