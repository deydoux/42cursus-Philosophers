/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 22:27:17 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/02 19:07:06 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_exit(int status, t_philo *philo)
{
	sem_close(philo->exit_sem);
	sem_close(philo->forks_sem);
	sem_close(philo->write_sem);
	pthread_join(philo->thread, NULL);
	exit(status);
}
