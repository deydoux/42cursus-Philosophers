/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:36:35 by deydoux           #+#    #+#             */
/*   Updated: 2024/04/19 18:52:56 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

void	*routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->common->mutex);
	pthread_mutex_unlock(&philo->common->mutex);
	if (!philo->common->ready)
		return (NULL);
	printf("%zu %s I'm alive!\n", get_ms_time() - philo->common->start_time, philo->id);
	return (NULL);
}
