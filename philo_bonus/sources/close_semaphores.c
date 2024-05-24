/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_semaphores.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:44:39 by deydoux           #+#    #+#             */
/*   Updated: 2024/05/24 11:46:04 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	safe_sem_close(sem_t *sem)
{
	if (sem)
		sem_close(sem);
}

void	close_semaphores(t_philo philo)
{
	safe_sem_close(philo.forks);
	safe_sem_close(philo.write);
}
