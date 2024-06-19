/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:22:03 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/19 14:40:21 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

void	philo_sleep(useconds_t time, t_philo *philo)
{
	size_t	current_time;

	current_time = get_ms_time();
	if (current_time + time / 1000 >= philo->die_time)
		time = (philo->die_time - current_time) * 1000;
	usleep(time);
}
