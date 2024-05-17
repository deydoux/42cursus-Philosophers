/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:36:35 by deydoux           #+#    #+#             */
/*   Updated: 2024/05/17 15:12:37 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

// static void	philo_usleep(useconds_t time, t_philo *philo)
// {
// 	const size_t	time_to_die = get_ms_time() - philo->common->start_time ;

// 	if (time < time_to_die)
// 		usleep(time);
// 	usleep(philo->common->time_to_die);
// 	pthread_mutex_lock(&philo->common->mutex.data);
// 	if (!philo->common->kill)
// 		printf(DIE_FORMAT, get_ms_time() - philo->common->start_time,
// 			philo->id);
// 	philo->common->kill = true;
// 	pthread_mutex_unlock(&philo->common->mutex.data);
// }

// static bool

// static bool	philo_take_forks(t_philo *philo)
// {
// 	const size_t	max_time = philo->common->start_time + philo->last_eat
// 		+ philo->common->time_to_die;

// 	pthread_mutex_lock(&philo->right_fork.mutex.data);
// 	while (philo->right_fork.taken)
// 	{
// 		if (get_ms_time() >= max_time)
// 		{
// 			pthread_mutex_unlock(&philo->right_fork.mutex.data);
// 			return (true);
// 		}
// 	}
// 	philo->right_fork.taken = true;
// 	pthread_mutex_unlock(&philo->right_fork.mutex.data);
// }

static bool	philo_sleep(t_philo *philo)
{
	(void)philo;
	return (false);
}

static bool	philo_think(t_philo *philo)
{
	(void)philo;
	return (true);
}

static bool	philo_eat(t_philo *philo)
{
	if (philo->common->limit_eat
		&& ++philo->eat_count == philo->common->must_eat)
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
	usleep(philo->common->time_to_eat);
	philo->right_fork.taken = false;
	philo->left_fork->taken = false;
	return (false);
}

static bool	init_routine(t_philo *philo)
{
	printf(THINK_FORMAT, (size_t)0, philo->id);
	if (philo->common->time_to_eat > philo->common->time_to_die)
	{
		pthread_mutex_unlock(&philo->common->mutex.data);
		usleep(philo->common->time_to_die);
		pthread_mutex_lock(&philo->common->mutex.data);
		if (!philo->common->kill)
			printf(DIE_FORMAT, get_ms_time() - philo->common->start_time,
				philo->id);
		philo->common->kill = true;
		pthread_mutex_unlock(&philo->common->mutex.data);
		return (true);
	}
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
