/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:11:55 by deydoux           #+#    #+#             */
/*   Updated: 2024/05/28 19:04:46 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

static bool	monitoring_process(t_philo *philo, pid_t *pid)
{
	size_t	time;

	*pid = fork();
	if (*pid)
		return (*pid < 0);
	time = get_ms_time();
	if (time < philo->die_time)
		usleep((philo->die_time - time) * 1000);
	philo_print(philo, DIE_FORMAT, NULL, true);
	exit(EXIT_FAILURE);
}

static bool	take_forks_process(t_philo *philo, pid_t *pid)
{
	*pid = fork();
	if (*pid)
		return (*pid < 0);
	sem_wait(philo->common->forks_sem);
	if (philo_print(philo, FORK_FORMAT, NULL, true))
		exit(EXIT_FAILURE);
	sem_wait(philo->common->forks_sem);
	exit(philo_print(philo, FORK_FORMAT, NULL, true));
}

static void	safe_kill(pid_t pid, int sig)
{
	if (pid > 0)
		kill(pid, sig);
}

bool	take_forks(t_philo *philo)
{
	bool	exit_code;
	int		status;
	pid_t	pids[2];

	ft_bzero(pids, sizeof(pids));
	exit_code = monitoring_process(philo, &pids[1])
		|| take_forks_process(philo, &pids[0]);
	if (exit_code)
	{
		sem_wait(philo->common->lock_sem);
		ft_putstr_fd(ERR_FORK, STDERR_FILENO);
		philo->common->exit = true;
		sem_post(philo->common->lock_sem);
	}
	waitpid(0, &status, 0);
	if (status)
	{
		philo->common->exit = true;
		sem_post(philo->common->lock_sem);
		exit_code = true;
	}
	safe_kill(pids[0], SIGHUP);
	safe_kill(pids[1], SIGHUP);
	return (exit_code);
}
