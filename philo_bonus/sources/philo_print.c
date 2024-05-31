/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 22:40:34 by deydoux           #+#    #+#             */
/*   Updated: 2024/05/31 22:30:57 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_print(t_philo *philo, char *format, size_t *time_ptr)
{
	size_t	time;

	sem_wait(philo->write_sem);
	time = get_ms_time();
	if (time >= philo->die_time)
	{
		printf(FORMAT_DIE, time - philo->start_time, philo->id);
		philo_exit(EXIT_FAILURE, philo);
	}
	else if (format)
		printf(format, time - philo->start_time, philo->id);
	sem_post(philo->write_sem);
	if (time_ptr)
		*time_ptr = time;
}
