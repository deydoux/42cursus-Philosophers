/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:49:47 by deydoux           #+#    #+#             */
/*   Updated: 2024/05/17 16:04:02 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

bool	sleep_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->common->mutex.data);
	if (philo->common->kill)
	{
		pthread_mutex_unlock(&philo->common->mutex.data);
		return (true);
	}
	printf(SLEEP_FORMAT, get_ms_time() - philo->common->start_time, philo->id);
	pthread_mutex_unlock(&philo->common->mutex.data);
	return (philo_sleep(philo->common.time_to_sleep, philo));
}
