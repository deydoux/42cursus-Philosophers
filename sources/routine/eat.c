/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:31:51 by deydoux           #+#    #+#             */
/*   Updated: 2024/05/18 21:53:56 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

static bool	take_fork(t_philo_fork *fork, t_philo *philo)
{
	pthread_mutex_lock(&fork->mutex.data);
	while (fork->taken && !philo->common->kill)
	{
		usleep(100);
		if (get_ms_time() >= philo->die_time)
		{
			pthread_mutex_unlock(&fork->mutex.data);
			return (true);
		}
	}
	fork->taken = true;
	pthread_mutex_unlock(&fork->mutex.data);
	pthread_mutex_lock(&philo->common->mutex.data);
	if (!philo->common->kill)
		printf(FORK_FORMAT, get_ms_time() - philo->common->start_time,
			philo->id);
	pthread_mutex_unlock(&philo->common->mutex.data);
	return (false);
}

static bool	take_forks(t_philo *philo)
{
	if (take_fork(&philo->right_fork, philo)
		|| take_fork(philo->left_fork, philo))
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
	philo->die_time = get_ms_time();
	printf(EAT_FORMAT, philo->die_time - philo->common->start_time, philo->id);
	pthread_mutex_unlock(&philo->common->mutex.data);
	philo->die_time += philo->common->time_to_die;
	if (philo_sleep(philo->common->time_to_eat, philo))
		return (true);
	philo->right_fork.taken = false;
	philo->left_fork->taken = false;
	return (false);
}
