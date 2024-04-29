/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:36:35 by deydoux           #+#    #+#             */
/*   Updated: 2024/04/29 16:08:55 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

static bool	print_state(char *format, t_philo *philo)
{
	pthread_mutex_lock(&philo->common->mutex.data);
	if (philo->common->kill)
	{
		pthread_mutex_unlock(&philo->common->mutex.data);
		return (true);
	}
	printf(format, get_ms_time() - philo->common->start_time, philo->id);
	pthread_mutex_unlock(&philo->common->mutex.data);
	return (false);
}

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
		print_state(FORK_FORMAT, philo);
		pthread_mutex_lock(&philo->left_fork->data);
		print_state(FORK_FORMAT, philo);
		print_state(EAT_FORMAT, philo);
		usleep(philo->common->time_to_eat);
		pthread_mutex_unlock(&philo->right_fork.data);
		pthread_mutex_unlock(&philo->left_fork->data);
		print_state(SLEEP_FORMAT, philo);
		usleep(philo->common->time_to_sleep);
	}
	return (NULL);
}
