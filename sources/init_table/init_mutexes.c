/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutexes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:59:21 by deydoux           #+#    #+#             */
/*   Updated: 2024/04/30 14:07:08 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_table.h"

static bool	init_mutex(t_safe_mutex *mutex)
{
	mutex->initialized = !pthread_mutex_init(&mutex->data, NULL);
	if (!mutex->initialized)
	{
		ft_putstr_fd(ERR_INIT_MUTEXES, STDERR_FILENO);
		return (true);
	}
	return (false);
}

static bool	init_fork_mutexes(t_table *table)
{
	size_t	i;

	i = 0;
	while (i < table->n_philo)
		if (init_mutex(&table->philos[i++].right_fork.mutex))
			return (true);
	return (false);
}

bool	init_mutexes(t_table *table)
{
	return (init_mutex(&table->common.mutex) || init_fork_mutexes(table));
}
