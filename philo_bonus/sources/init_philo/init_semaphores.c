/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_semaphores.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:18:15 by deydoux           #+#    #+#             */
/*   Updated: 2024/05/23 13:16:21 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_philo.h"

static bool	init_semaphore(sem_t **sem, char *name, unsigned int value)
{
	sem_unlink(name);
	*sem = sem_open(name, O_CREAT | O_EXCL, 0, value);
	return (!*sem);
}

bool	init_semaphores(t_philo *philo)
{
	if (init_semaphore(&philo->forks, SEM_NAME_FORKS, philo->n % 2)
		|| init_semaphore(&philo->write, SEM_NAME_WRITE, 0))
	{
		ft_putstr_fd(ERR_INIT_SEM, STDERR_FILENO);
		return (true);
	}
	return (false);
}
