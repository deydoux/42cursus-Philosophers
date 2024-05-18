/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:49:47 by deydoux           #+#    #+#             */
/*   Updated: 2024/05/18 23:25:42 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

bool	sleep_routine(t_philo *philo)
{
	if (philo_print(philo, SLEEP_FORMAT, NULL))
		return (true);
	philo_sleep(philo->common->time_to_sleep, philo);
	return (false);
}
