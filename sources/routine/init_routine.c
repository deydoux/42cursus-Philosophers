/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_routine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:45:48 by deydoux           #+#    #+#             */
/*   Updated: 2024/05/21 18:17:09 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

static bool	last_even_routine(t_philo *philo)
{
	pthread_mutex_unlock(&philo->common->mutex.data);
	philo->die_time = philo->common->start_time + philo->common->time_to_die
		/ 1000;
	return (eat_routine(philo));
}

static bool	even_routine(t_philo *philo)
{
	if (philo->last)
		return (last_even_routine(philo));
	printf(FORK_FORMAT, (size_t)0, philo->id);
	printf(FORK_FORMAT, (size_t)0, philo->id);
	printf(EAT_FORMAT, (size_t)0, philo->id);
	pthread_mutex_unlock(&philo->common->mutex.data);
	philo->die_time = philo->common->start_time + philo->common->time_to_die
		/ 1000;
	philo_sleep(philo->common->time_to_eat, philo);
	pthread_mutex_lock(&philo->right_fork.change_mutex.data);
	philo->right_fork.taken = false;
	pthread_mutex_unlock(&philo->right_fork.change_mutex.data);
	pthread_mutex_lock(&philo->left_fork->change_mutex.data);
	philo->left_fork->taken = false;
	pthread_mutex_unlock(&philo->left_fork->change_mutex.data);
	return (false);
}

static bool	odd_routine(t_philo *philo)
{
	pthread_mutex_unlock(&philo->common->mutex.data);
	philo->die_time = philo->common->start_time + philo->common->time_to_die
		/ 1000;
	philo_sleep(philo->common->time_to_eat / 2, philo);
	return (eat_routine(philo));
}

bool	init_routine(t_philo *philo)
{
	if (philo->common->limit_eat && !philo->common->must_eat)
	{
		pthread_mutex_unlock(&philo->common->mutex.data);
		return (true);
	}
	printf(THINK_FORMAT, (size_t)0, philo->id);
	if (philo->odd)
		return (odd_routine(philo));
	return (even_routine(philo));
}
