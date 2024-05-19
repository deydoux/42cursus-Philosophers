/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:31:51 by deydoux           #+#    #+#             */
/*   Updated: 2024/05/19 18:52:38 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

static bool	take_fork(t_philo_fork *fork, t_philo *philo)
{
	pthread_mutex_lock(&fork->mutex.data);
	while (fork->taken && !philo_print(philo, NULL, NULL))
		usleep(FORK_USLEEP);
	fork->taken = true;
	pthread_mutex_unlock(&fork->mutex.data);
	return (philo_print(philo, FORK_FORMAT, NULL));
}

static bool	take_forks(t_philo *philo)
{
	return (take_fork(&philo->right_fork, philo)
		|| take_fork(philo->left_fork, philo));
}

bool	eat_routine(t_philo *philo)
{
	if (take_forks(philo) || philo_print(philo, EAT_FORMAT, &philo->die_time))
		return (true);
	philo->die_time += philo->common->time_to_die / 1000;
	philo_sleep(philo->common->time_to_eat, philo);
	philo->right_fork.taken = false;
	philo->left_fork->taken = false;
	if (philo->common->limit_eat
		&& ++philo->eat_count == philo->common->must_eat)
		return (true);
	return (false);
}
