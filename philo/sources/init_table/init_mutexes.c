/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutexes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:44:32 by deydoux           #+#    #+#             */
/*   Updated: 2024/04/09 13:13:40 by deydoux          ###   ########.fr       */
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
			return (true);
	}
	return (false);
}

bool	init_mutexes(t_table *table)
{
	if (pthread_mutex_init(&table->mutex, NULL) || init_fork_mutexes(table))
	{
		ft_putstr_fd(ERR_INIT_MUTEXES, STDERR_FILENO);
		return (true);
	}
	return (false);
}
