/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:31:51 by deydoux           #+#    #+#             */
/*   Updated: 2024/05/30 16:26:59 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

static bool	take_forks(t_philo *philo)
{
	sem_wait(philo->common->forks_sem);
	if (philo_print(philo, FORK_FORMAT, NULL))
		return (true);
	sem_wait(philo->common->forks_sem);
	return (philo_print(philo, FORK_FORMAT, NULL));
}

bool	eat_routine(t_philo *philo)
{
	if (take_forks(philo))
		return (true);
	sem_wait(philo->common->die_time_sem);
	if (philo_print(philo, EAT_FORMAT, &philo->die_time))
	{
		sem_post(philo->common->die_time_sem);
		return (true);
	}
	philo->die_time += philo->common->time_to_die / 1000;
	sem_post(philo->common->die_time_sem);
	philo_sleep(philo->common->time_to_eat, philo);
	sem_post(philo->common->forks_sem);
	sem_post(philo->common->forks_sem);
	return (false);
}
