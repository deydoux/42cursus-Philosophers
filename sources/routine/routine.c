/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:36:35 by deydoux           #+#    #+#             */
/*   Updated: 2024/05/19 18:52:58 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

void	*routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->common->mutex.data);
	if (philo->common->exit)
	{
		pthread_mutex_unlock(&philo->common->mutex.data);
		return (NULL);
	}
	if (!init_routine(philo))
		while (!sleep_routine(philo) && !think_routine(philo) && !eat_routine(philo))
			;
	return (NULL);
}
