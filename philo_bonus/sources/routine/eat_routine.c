/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:31:51 by deydoux           #+#    #+#             */
/*   Updated: 2024/05/27 07:41:34 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

static bool	take_fork(t_philo *philo)
{
	pid_t	pids[2];
	size_t	time;
	int		status;

	pids[0] = fork();
	if (!pids[0])
	{
		sem_wait(philo->common->forks_sem);
		exit(EXIT_SUCCESS);
	}
	if (pids[0] < 0)
	{
		ft_putstr_fd(ERR_FORK, STDERR_FILENO);
		return (true);
	}
	pids[1] = fork();
	if (!pids[1])
	{
		time = get_ms_time();
		if (time < philo->die_time)
			sleep(philo->die_time - time);
		exit(EXIT_FAILURE);
	}
	if (pids[1] < 0)
	{
		ft_putstr_fd(ERR_FORK, STDERR_FILENO);
		return (true);
	}
	waitpid(0, &status, 0);
	if (status)
		kill(pids[0], SIGHUP);
	else
		kill(pids[1], SIGHUP);
	return (philo_print(philo, FORK_FORMAT, NULL));
}

static bool	take_forks(t_philo *philo)
{
	return (take_fork(philo) || take_fork(philo));
}

bool	eat_routine(t_philo *philo)
{
	if (take_forks(philo) || philo_print(philo, EAT_FORMAT, &philo->die_time))
		return (true);
	philo->die_time += philo->common->time_to_die / 1000;
	philo_sleep(philo->common->time_to_eat, philo);
	sem_post(philo->common->forks_sem);
	sem_post(philo->common->forks_sem);
	return (false);
}
