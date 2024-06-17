/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:36:35 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/17 12:28:10 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	eat_routine(t_philo *philo)
{
	size_t	time;

	sem_wait(philo->forks_sem);
	if (philo_print(philo, FORMAT_FORK, NULL))
	{
		sem_post(philo->forks_sem);
		return (true);
	}
	sem_wait(philo->forks_sem);
	if (philo_print(philo, FORMAT_FORK, NULL)
		|| philo_print(philo, FORMAT_EAT, &time))
	{
		sem_post(philo->forks_sem);
		sem_post(philo->forks_sem);
		return (true);
	}
	philo->die_time = time + philo->time_to_die / 1000;
	usleep(philo->time_to_eat);
	sem_post(philo->forks_sem);
	sem_post(philo->forks_sem);
	return (false);
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

static bool	init_routine(t_philo *philo)
{
	if (philo->limit_eat && !philo->must_eat)
	{
		sem_post(philo->done_sem);
		return (true);
	}
	if (philo->id % 2)
		even_routine(philo);
	else
		odd_routine(philo);
	return (false);
}

void	*routine(t_philo *philo)
{
	if (init_routine(philo))
		return (NULL);
	while (true)
	{
		if (philo_print(philo, FORMAT_SLEEP, NULL))
			break ;
		if (philo->limit_eat && ++philo->eat_count == philo->must_eat)
		{
			sem_post(philo->done_sem);
			break ;
		}
		usleep(philo->time_to_sleep);
		if (philo_print(philo, FORMAT_THINK, NULL))
			break ;
		if (philo->n % 2)
			usleep(ODD_USLEEP);
		if (eat_routine(philo))
			break ;
	}
	return (NULL);
}
