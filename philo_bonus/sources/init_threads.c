/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 10:59:34 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/02 19:14:07 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	monitor(t_philo *philo)
{
	size_t	die_time;
	size_t	time;

	usleep(philo->time_to_eat / 2);
	while (true)
	{
		die_time = philo->die_time;
		time = get_ms_time();
		if (die_time > time)
			usleep(die_time - time);
		philo_print(philo, NULL, NULL);
	}
}

void	init_threads(t_philo *philo)
{
	if (pthread_create(&philo->thread, NULL, (void *)routine, philo))
	{
		sem_wait(philo->write_sem);
		ft_putstr_fd(ERR_INIT_THREADS, STDERR_FILENO);
		philo_exit(EXIT_FAILURE, philo);
	}
	monitor(philo);
}
