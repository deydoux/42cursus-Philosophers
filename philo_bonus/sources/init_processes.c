/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_processes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:56:35 by deydoux           #+#    #+#             */
/*   Updated: 2024/05/24 17:04:38 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	init_process(t_philo philo, pid_t *pid)
{
	philo.last = philo.id == philo.n;
	philo.odd = philo.id % 2;
	*pid = fork();
	if (!*pid)
	{
		routine(philo);
		safe_sem_close(philo.forks);
		safe_sem_close(philo.write);
		exit(EXIT_SUCCESS);
	}
	if (*pid < 0)
	{
		ft_putstr_fd(ERR_INIT_PROCESS, STDERR_FILENO);
		return (true);
	}
	return (false);
}

bool	init_processes(t_philo *philo)
{
	philo->pids = ft_calloc(philo->n, sizeof(*philo->pids));
	if (!philo->pids)
	{
		ft_putstr_fd(ERR_INIT_PROCESS, STDERR_FILENO);
		return (true);
	}
	while (philo->id++ < philo->n)
	{
		if (init_process(*philo, &philo->pids[philo->id - 1]))
		{
			ft_putstr_fd(ERR_INIT_PROCESS, STDERR_FILENO);
			return (true);
		}
	}
	sem_post(philo->write);
	return (false);
}
