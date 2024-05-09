/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:36:35 by deydoux           #+#    #+#             */
/*   Updated: 2024/05/09 15:41:04 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

static bool	philo_sleep(t_philo *philo)
{
	(void)philo;
	return (false);
}

static bool	philo_think(t_philo *philo)
{
	(void)philo;
	return (false);
}

static bool	philo_eat(t_philo *philo)
{
	(void)philo;
	return (false);
}

static bool	init_routine(t_philo *philo)
{
	printf(THINK_FORMAT, (size_t)0, philo->id);
	if (!philo->even)
	{
		pthread_mutex_unlock(&philo->common->mutex.data);
		usleep(MIN_TIME / 2);
		return (philo_eat(philo));
	}
	printf(FORK_FORMAT, (size_t)0, philo->id);
	printf(FORK_FORMAT, (size_t)0, philo->id);
	printf(EAT_FORMAT, (size_t)0, philo->id);
	pthread_mutex_unlock(&philo->common->mutex.data);
	usleep(philo->common->time_to_eat);
	return (false);
}

void	*routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->common->mutex.data);
	if (philo->common->kill)
	{
		pthread_mutex_unlock(&philo->common->mutex.data);
		return (NULL);
	}
	if (!init_routine(philo))
		while (!philo_sleep(philo) && !philo_think(philo) && philo_eat(philo))
			;
	return (NULL);
}
