/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_sems.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:58:10 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/06 16:58:59 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	safe_sem_close(sem_t *sem)
{
	if (sem)
		sem_close(sem);
}

void	close_sems(t_philo philo)
{
	safe_sem_close(philo.done_sem);
	safe_sem_close(philo.exit_sem);
	safe_sem_close(philo.exit_change_sem);
	safe_sem_close(philo.forks_sem);
	safe_sem_close(philo.write_sem);
}
