/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 10:59:34 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/05 11:32:18 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	init_thread(t_philo *philo, void *function, t_safe_thread *thread)
{
	thread->initialized = !pthread_create(&thread->data, NULL, function, philo);
	if (!thread->initialized)
	{
		ft_putstr_fd(ERR_INIT_THREADS, STDERR_FILENO);
		return (true);
	}
	return (false);
}

static void	destroy_thread(t_safe_thread thread)
{
	if (thread.initialized)
		pthread_join(thread.data, NULL);
}

static void	*monitor(t_philo *philo)
{
	size_t	die_time;
	size_t	time;

	if (philo->time_to_eat < philo->time_to_die)
		usleep(philo->time_to_eat / 2);
	else
		usleep(philo->time_to_die / 2);
	while (true)
	{
		die_time = philo->die_time;
		time = get_ms_time();
		if (die_time > time)
			usleep(die_time - time);
		if (philo_print(philo, NULL, NULL))
			break ;
	}
	return (NULL);
}

void	init_threads(t_philo *philo)
{
	t_safe_thread	threads[2];

	ft_bzero(threads, sizeof(threads));
	if (init_thread(philo, monitor, &threads[0])
		|| init_thread(philo, routine, &threads[1]))
	{
		while (philo->n--)
			sem_post(philo->done_sem);
		sem_wait(philo->write_sem);
		ft_putstr_fd(ERR_INIT_THREADS, STDERR_FILENO);
		usleep(philo->time_to_die);
		sem_post(philo->write_sem);
	}
	sem_wait(philo->exit_sem);
	sem_post(philo->exit_sem);
	sem_wait(philo->exit_change_sem);
	philo->exit = true;
	sem_post(philo->exit_change_sem);
	destroy_thread(threads[0]);
	destroy_thread(threads[1]);
	sem_post(philo->done_sem);
	sem_close(philo->done_sem);
	sem_close(philo->exit_sem);
	sem_close(philo->exit_change_sem);
	sem_close(philo->forks_sem);
	sem_close(philo->write_sem);
	exit(EXIT_SUCCESS);
}
