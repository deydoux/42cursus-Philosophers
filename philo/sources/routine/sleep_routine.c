/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:49:47 by deydoux           #+#    #+#             */
/*   Updated: 2024/05/22 12:03:05 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

bool	sleep_routine(t_philo *philo)
{
	if (philo_print(philo, SLEEP_FORMAT, NULL))
		return (true);
	if (philo->common->limit_eat
		&& ++philo->eat_count == philo->common->must_eat)
		return (true);
	philo_sleep(philo->common->time_to_sleep, philo);
	return (false);
}
