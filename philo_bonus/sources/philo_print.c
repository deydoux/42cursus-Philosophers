/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 22:40:34 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/06 17:05:41 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	print_die(t_philo *philo, size_t time)
{
	while (philo->n--)
		sem_post(philo->done_sem);
	printf(FORMAT_DIE, time - philo->start_time, philo->id);
	usleep(philo->time_to_die);
	sem_post(philo->write_sem);
	return (true);
}

bool	philo_print(t_philo *philo, char *format, size_t *time_ptr)
{
	size_t	time;

	sem_wait(philo->write_sem);
	sem_wait(philo->exit_change_sem);
	if (philo->exit)
	{
		sem_post(philo->exit_change_sem);
		sem_post(philo->write_sem);
		return (true);
	}
	sem_post(philo->exit_change_sem);
	time = get_ms_time();
	if (time >= philo->die_time)
		return (print_die(philo, time));
	else if (format)
		printf(format, time - philo->start_time, philo->id);
	sem_post(philo->write_sem);
	if (time_ptr)
		*time_ptr = time;
	return (false);
}
