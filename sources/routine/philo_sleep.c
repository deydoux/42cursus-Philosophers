/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:22:03 by deydoux           #+#    #+#             */
/*   Updated: 2024/05/18 22:02:52 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

bool	philo_sleep(useconds_t time, t_philo *philo)
{
	size_t	current_time;

	current_time = get_ms_time();
	if (current_time < philo->die_time
		&& philo->die_time - current_time > time)
	{
		usleep(time);
		return (false);
	}
	usleep(philo->die_time - current_time);
	pthread_mutex_lock(&philo->common->mutex.data);
	if (!philo->common->kill)
		printf(DIE_FORMAT, get_ms_time() - philo->common->start_time,
			philo->id);
	philo->common->kill = true;
	pthread_mutex_unlock(&philo->common->mutex.data);
	return (true);
}
