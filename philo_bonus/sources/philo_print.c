/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 22:40:34 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/02 21:59:01 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	philo_print(t_philo *philo, char *format, size_t *time_ptr)
{
	size_t	time;

	sem_wait(philo->write_sem);
	if (philo->exit)
	{
		sem_post(philo->write_sem);
		return (true);
	}
	time = get_ms_time();
	if (time >= philo->die_time)
	{
		sem_post(philo->exit_sem);
		printf(FORMAT_DIE, time - philo->start_time, philo->id);
		usleep(philo->time_to_die);
		sem_post(philo->write_sem);
		return (true);
	}
	else if (format)
		printf(format, time - philo->start_time, philo->id);
	sem_post(philo->write_sem);
	if (time_ptr)
		*time_ptr = time;
	return (false);
}
