/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_processes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:56:35 by deydoux           #+#    #+#             */
/*   Updated: 2024/05/31 22:34:15 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	init_process(t_table *table, pid_t *pid)
{
	*pid = fork();
	if (!*pid)
	{
		free(table->pids);
		init_thread(&table->philo);
		philo_exit(EXIT_SUCCESS, &table->philo);
	}
	return (*pid <= 0);
}

bool	init_processes(t_table *table)
{
	table->pids = ft_calloc(table->philo.n, sizeof(*table->pids));
	if (!table->pids)
	{
		ft_putstr_fd(ERR_INIT_PROCESSES, STDERR_FILENO);
		return (true);
	}
	table->philo.start_time = get_ms_time();
	table->philo.die_time = table->philo.start_time + table->philo.time_to_die
		/ 1000;
	while (table->philo.id++ < table->philo.n)
	{
		if (init_process(table, &table->pids[table->philo.id - 1]))
		{
			ft_putstr_fd(ERR_INIT_PROCESSES, STDERR_FILENO);
			return (true);
		}
	}
	return (false);
}
