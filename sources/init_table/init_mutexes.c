/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutexes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:44:32 by deydoux           #+#    #+#             */
/*   Updated: 2024/04/16 15:22:26 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_table.h"

static bool	init_fork_mutexes(t_table *table)
{
	size_t	i;

	i = 0;
	while (i < table->size)
	{
		if (pthread_mutex_init(&table->philos[i++].fork_r.mutex, NULL))
		{
			while (i--)
				pthread_mutex_destroy(&table->philos[i].fork_r.mutex);
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
