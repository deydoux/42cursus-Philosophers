/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_processes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:56:35 by deydoux           #+#    #+#             */
/*   Updated: 2024/05/23 18:35:28 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	init_process(t_philo philo, pid_t *pid)
{
	philo.last = philo.id == philo.n;
	philo.odd = philo.id % 2;
	*pid = fork();
	if (!*pid)
		routine(philo);
	if (*pid < 0)
	{
		ft_putstr_fd(ERR_INIT_PROCESS, STDERR_FILENO);
		return (true);
	}
	return (false);
}

bool	init_processes(t_philo philo, pid_t **pids)
{
	*pids = ft_calloc(philo.n, sizeof(**pids));
	if (!pids)
	{
		ft_putstr_fd(ERR_INIT_PROCESS, STDERR_FILENO);
		return (true);
	}
	while (philo.id++ < philo.n)
	{
		if (init_process(philo, &(*pids)[philo.id - 1]))
		{
			ft_putstr_fd(ERR_INIT_PROCESS, STDERR_FILENO);
			return (true);
		}
		if (!(*pids)[philo.id - 1])
			break ;
	}
	return (false);
}
