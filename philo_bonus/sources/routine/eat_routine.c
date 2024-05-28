/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:31:51 by deydoux           #+#    #+#             */
/*   Updated: 2024/05/28 18:49:52 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

bool	eat_routine(t_philo *philo)
{
	if (take_forks(philo)
		|| philo_print(philo, EAT_FORMAT, &philo->die_time, false))
		return (true);
	philo->die_time += philo->common->time_to_die / 1000;
	philo_sleep(philo->common->time_to_eat, philo);
	sem_post(philo->common->forks_sem);
	sem_post(philo->common->forks_sem);
	return (false);
}
