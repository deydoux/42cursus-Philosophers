/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:36:35 by deydoux           #+#    #+#             */
/*   Updated: 2024/05/18 23:33:16 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

static bool	init_routine(t_philo *philo)
{
	printf(THINK_FORMAT, (size_t)0, philo->id);
	if (!philo->even)
	{
		pthread_mutex_unlock(&philo->common->mutex.data);
		philo->die_time = philo->common->start_time
			+ philo->common->time_to_die / 1000;
		philo_sleep(MIN_TIME / 2, philo);
		return (eat(philo));
	}
	printf(FORK_FORMAT, (size_t)0, philo->id);
	printf(FORK_FORMAT, (size_t)0, philo->id);
	printf(EAT_FORMAT, (size_t)0, philo->id);
	pthread_mutex_unlock(&philo->common->mutex.data);
	philo->die_time = philo->common->start_time + philo->common->time_to_die
		/ 1000;
	philo_sleep(philo->common->time_to_eat, philo);
	philo->right_fork.taken = false;
	philo->left_fork->taken = false;
	return (false);
}

void	*routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->common->mutex.data);
	if (philo->common->exit)
	{
		pthread_mutex_unlock(&philo->common->mutex.data);
		return (NULL);
	}
	if (!init_routine(philo))
		while (!sleep_routine(philo) && !think(philo) && !eat(philo))
			;
	return (NULL);
}
