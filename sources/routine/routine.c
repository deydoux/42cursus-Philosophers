/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:36:35 by deydoux           #+#    #+#             */
/*   Updated: 2024/04/30 13:45:06 by deydoux          ###   ########.fr       */
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

static bool	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->right_fork.data);
	if (print_state(FORK_FORMAT, philo))
		return (true);
	pthread_mutex_lock(&philo->left_fork->data);
	if (print_state(FORK_FORMAT, philo) || print_state(EAT_FORMAT, philo))
		return (true);
	usleep(philo->common->time_to_eat);
	pthread_mutex_unlock(&philo->right_fork.data);
	pthread_mutex_unlock(&philo->left_fork->data);
	return (false);
}

static bool	philo_sleep(t_philo *philo)
{
	if (print_state(SLEEP_FORMAT, philo))
		return (true);
	usleep(philo->common->time_to_sleep);
	return (false);
}

static bool	philo_think(t_philo *philo)
{
	return (print_state(THINK_FORMAT, philo));
}

void	*routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->common->mutex.data);
	pthread_mutex_unlock(&philo->common->mutex.data);
	if (philo->common->kill)
		return (NULL);
	printf(THINK_FORMAT, (size_t)0, philo->id);
	philo->last_eat = philo->common->start_time;
	if (philo->i % 2)
		usleep(philo->common->time_to_eat / 2);
	while (!(philo_eat(philo) || philo_sleep(philo) || philo_think(philo)))
		;
	return (NULL);
}
