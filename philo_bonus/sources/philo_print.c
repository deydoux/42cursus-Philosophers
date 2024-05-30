/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 22:40:34 by deydoux           #+#    #+#             */
/*   Updated: 2024/05/30 15:40:28 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	philo_print(t_philo *philo, char *format, size_t *time_ptr)
{
	bool	exit_code;
	size_t	time;

	sem_wait(philo->common->lock_sem);
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
	sem_post(philo->common->lock_sem);
	if (time_ptr)
		*time_ptr = time;
	return (exit_code);
}
