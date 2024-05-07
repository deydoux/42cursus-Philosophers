/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:36:35 by deydoux           #+#    #+#             */
/*   Updated: 2024/05/07 14:24:52 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

static void	init_routine(t_philo *philo)
{
	printf(THINK_FORMAT, (size_t)0, philo->id);
	if (philo->even)
	{
		philo->right_fork.used = true;
		philo->left_fork->used = true;
		printf(FORK_FORMAT, (size_t)0, philo->id);
		printf(FORK_FORMAT, (size_t)0, philo->id);
		printf(EAT_FORMAT, (size_t)0, philo->id);
		usleep(philo->common->time_to_eat);
	}
	else
		usleep(philo->common->time_to_eat / 2);
}

void	*routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->common->mutex.data);
	pthread_mutex_unlock(&philo->common->mutex.data);
	if (philo->common->kill)
		return (NULL);
	philo->last_eat = philo->common->start_time;
	init_routine(philo);
	return (NULL);
}
