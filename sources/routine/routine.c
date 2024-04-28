/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:36:35 by deydoux           #+#    #+#             */
/*   Updated: 2024/04/28 21:30:51 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

void	*routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->common->mutex.data);
	pthread_mutex_unlock(&philo->common->mutex.data);
	if (philo->common->kill)
		return (NULL);
	printf(THINK_FORMAT, (size_t)0, philo->id);
	if (philo->i % 2)
		usleep(philo->common->time_to_eat / 2);
	while (true)
	{
		pthread_mutex_lock(&philo->right_fork.data);
		printf(FORK_FORMAT, get_ms_time() - philo->common->start_time, philo->id);
		pthread_mutex_lock(&philo->left_fork->data);
		printf(FORK_FORMAT, get_ms_time() - philo->common->start_time, philo->id);
		printf(EAT_FORMAT, get_ms_time() - philo->common->start_time, philo->id);
		usleep(philo->common->time_to_eat);
		pthread_mutex_unlock(&philo->right_fork.data);
		pthread_mutex_unlock(&philo->left_fork->data);
		printf(SLEEP_FORMAT, get_ms_time() - philo->common->start_time, philo->id);
		usleep(philo->common->time_to_sleep);
	}
	return (NULL);
}
