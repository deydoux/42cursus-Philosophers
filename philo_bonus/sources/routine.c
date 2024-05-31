/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:36:35 by deydoux           #+#    #+#             */
/*   Updated: 2024/05/31 22:31:18 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	eat_routine(t_philo *philo)
{
	size_t	time;

	sem_wait(philo->forks_sem);
	philo_print(philo, FORMAT_FORK, NULL);
	sem_wait(philo->forks_sem);
	philo_print(philo, FORMAT_FORK, NULL);
	philo_print(philo, FORMAT_EAT, &time);
	philo->die_time = time + philo->time_to_die / 1000;
	usleep(philo->time_to_eat);
	sem_post(philo->forks_sem);
	sem_post(philo->forks_sem);
}

static void	odd_routine(t_philo *philo)
{
	sem_wait(philo->write_sem);
	printf(FORMAT_THINK, (size_t)0, philo->id);
	printf(FORMAT_FORK, (size_t)0, philo->id);
	printf(FORMAT_FORK, (size_t)0, philo->id);
	printf(FORMAT_EAT, (size_t)0, philo->id);
	sem_post(philo->write_sem);
	usleep(philo->time_to_eat);
	sem_post(philo->forks_sem);
	sem_post(philo->forks_sem);
}

static void	even_routine(t_philo *philo)
{
	sem_wait(philo->write_sem);
	printf(FORMAT_THINK, (size_t)0, philo->id);
	sem_post(philo->write_sem);
	usleep(philo->time_to_eat / 2);
	eat_routine(philo);
}

static void	init_routine(t_philo *philo)
{
	if (philo->limit_eat && !philo->must_eat)
		philo_exit(EXIT_SUCCESS, philo);
	if (philo->id <= philo->n / 2)
		odd_routine(philo);
	else
		even_routine(philo);
}

void	*routine(t_philo *philo)
{
	init_routine(philo);
	while (true)
	{
		philo_print(philo, FORMAT_SLEEP, NULL);
		if (philo->limit_eat && ++philo->eat_count == philo->must_eat)
			philo_exit(EXIT_SUCCESS, philo);
		usleep(philo->time_to_sleep);
		philo_print(philo, FORMAT_THINK, NULL);
		eat_routine(philo);
	}
	return (NULL);
}
