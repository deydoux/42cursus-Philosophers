/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:36:35 by deydoux           #+#    #+#             */
/*   Updated: 2024/04/26 18:06:50 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

void	*routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->common->mutex.data);
	pthread_mutex_unlock(&philo->common->mutex.data);
	if (!philo->common->ready)
		return (NULL);
	if (philo->i % 2)
		ms_sleep(philo->common->time_to_eat / 2);
	printf("%zu %s I'm alive!\n", get_ms_time() - philo->common->start_time, philo->id);
	return (NULL);
}
