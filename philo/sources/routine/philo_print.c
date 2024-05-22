/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 22:40:34 by deydoux           #+#    #+#             */
/*   Updated: 2024/05/18 23:33:16 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

bool	philo_print(t_philo *philo, char *format, size_t *time_ptr)
{
	bool	exit_code;
	size_t	time;

	pthread_mutex_lock(&philo->common->mutex.data);
	time = get_ms_time();
	exit_code = philo->common->exit || time >= philo->die_time;
	if (exit_code)
	{
		if (!philo->common->exit)
		{
			printf(DIE_FORMAT, time - philo->common->start_time, philo->id);
			philo->common->exit = true;
		}
	}
	else if (format)
		printf(format, time - philo->common->start_time, philo->id);
	pthread_mutex_unlock(&philo->common->mutex.data);
	if (time_ptr)
		*time_ptr = time;
	return (exit_code);
}
