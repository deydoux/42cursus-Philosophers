/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:31:51 by deydoux           #+#    #+#             */
/*   Updated: 2024/05/17 15:46:26 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

static bool	take_fork(t_philo_fork *fork, size_t max_time)
{
	pthread_mutex_lock(&fork->mutex.data);
	while (fork->taken)
	{
		if (get_ms_time() >= max_time)
		{
			pthread_mutex_unlock(&fork->mutex.data);
			return (true);
		}
	}
	fork->taken = true;
	pthread_mutex_unlock(&fork->mutex.data);
	return (false);
}

static bool	take_forks(t_philo *philo)
{
	size_t	max_time;

	max_time = philo->common->start_time + philo->last_eat
		+ philo->common->time_to_die;
	if (take_fork(&philo->right_fork, max_time)
		|| take_fork(philo->left_fork, max_time))
	{
		pthread_mutex_lock(&philo->common->mutex.data);
		if (!philo->common->kill)
			printf(DIE_FORMAT, get_ms_time() - philo->common->start_time,
				philo->id);
		philo->common->kill = true;
		pthread_mutex_unlock(&philo->common->mutex.data);
		return (true);
	}
	return (false);
}

bool	eat(t_philo *philo)
{
	if (take_forks(philo) || (philo->common->limit_eat
			&& ++philo->eat_count == philo->common->must_eat))
		return (true);
	pthread_mutex_lock(&philo->common->mutex.data);
	if (philo->common->kill)
	{
		pthread_mutex_unlock(&philo->common->mutex.data);
		return (true);
	}
	philo->last_eat = get_ms_time() - philo->common->start_time;
	printf(EAT_FORMAT, philo->last_eat, philo->id);
	pthread_mutex_unlock(&philo->common->mutex.data);
	philo_sleep(philo->common->time_to_eat, philo);
	philo->right_fork.taken = false;
	philo->left_fork->taken = false;
	return (false);
}
