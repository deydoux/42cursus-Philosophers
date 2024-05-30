/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_routine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:45:48 by deydoux           #+#    #+#             */
/*   Updated: 2024/05/30 16:29:07 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

static bool	odd_routine(t_philo *philo)
{
	printf(FORK_FORMAT, (size_t)0, philo->id);
	printf(FORK_FORMAT, (size_t)0, philo->id);
	printf(EAT_FORMAT, (size_t)0, philo->id);
	sem_post(philo->common->lock_sem);
	sem_wait(philo->common->die_time_sem);
	philo->die_time = philo->common->start_time + philo->common->time_to_die
		/ 1000;
	sem_post(philo->common->die_time_sem);
	philo_sleep(philo->common->time_to_eat, philo);
	sem_post(philo->common->forks_sem);
	sem_post(philo->common->forks_sem);
	return (false);
}

static bool	even_routine(t_philo *philo)
{
	sem_post(philo->common->lock_sem);
	sem_wait(philo->common->die_time_sem);
	philo->die_time = philo->common->start_time + philo->common->time_to_die
		/ 1000;
	sem_post(philo->common->die_time_sem);
	philo_sleep(philo->common->time_to_eat / 2, philo);
	return (eat_routine(philo));
}

bool	init_routine(t_philo *philo)
{
	if (philo->common->limit_eat && !philo->common->must_eat)
	{
		sem_post(philo->common->lock_sem);
		return (true);
	}
	printf(THINK_FORMAT, (size_t)0, philo->id);
	if (philo->odd)
		return (odd_routine(philo));
	return (even_routine(philo));
}
