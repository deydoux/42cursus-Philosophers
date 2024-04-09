/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutexes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:44:32 by deydoux           #+#    #+#             */
/*   Updated: 2024/04/09 15:04:03 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_table.h"

static bool	init_fork_mutexes(t_table *table)
{
	size_t	i;

	i = 0;
	while (i < table->seats)
	{
		if (pthread_mutex_init(&table->philo[i++].fork.mutex, NULL))
		{
			while (i--)
				pthread_mutex_destroy(&table->philo[i].fork.mutex);
			return (true);
		}
	}
	return (false);
}

bool	init_mutexes(t_table *table)
{
	bool	error;

	error = pthread_mutex_init(&table->mutex, NULL);
	if (!error)
	{
		error = init_fork_mutexes(table);
		if (error)
			pthread_mutex_destroy(&table->mutex);
	}
	if (error)
		ft_putstr_fd(ERR_INIT_MUTEXES, STDERR_FILENO);
	return (error);
}
