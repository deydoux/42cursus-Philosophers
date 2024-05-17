/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:22:03 by deydoux           #+#    #+#             */
/*   Updated: 2024/05/17 16:00:06 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

bool	philo_sleep(useconds_t time, t_philo *philo)
{
	const size_t	time_to_die = get_ms_time() - philo->common->start_time;

	if (time < time_to_die)
	{
		usleep(time);
		return (false);
	}
	usleep(philo->common->time_to_die);
	pthread_mutex_lock(&philo->common->mutex.data);
	if (!philo->common->kill)
		printf(DIE_FORMAT, get_ms_time() - philo->common->start_time,
			philo->id);
	philo->common->kill = true;
	pthread_mutex_unlock(&philo->common->mutex.data);
	return (true);
}
