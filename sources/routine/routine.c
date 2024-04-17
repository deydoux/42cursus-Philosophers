/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:36:35 by deydoux           #+#    #+#             */
/*   Updated: 2024/04/17 13:37:09 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

void	*routine(t_philo *philo)
{
	struct timeval	tv;

	pthread_mutex_lock(philo->table_mutex);
	pthread_mutex_unlock(philo->table_mutex);
	gettimeofday(&tv, NULL);
	printf("%ld %s I'm alive!\n", tv.tv_usec, philo->id);
	return (NULL);
}
