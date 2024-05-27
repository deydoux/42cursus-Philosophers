/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:36:35 by deydoux           #+#    #+#             */
/*   Updated: 2024/05/27 07:36:46 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

void	*routine(t_philo *philo)
{
	sem_wait(philo->common->lock_sem);
	if (philo->common->exit)
	{
		sem_post(philo->common->lock_sem);
		return (NULL);
	}
	if (!init_routine(philo))
		while (!sleep_routine(philo) && !think_routine(philo)
			&& !eat_routine(philo))
			;
	return (NULL);
}
