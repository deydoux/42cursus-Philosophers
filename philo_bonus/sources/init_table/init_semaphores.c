/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_semaphores.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 07:45:31 by deydoux           #+#    #+#             */
/*   Updated: 2024/05/30 15:52:18 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_table.h"

static bool	init_semaphore(char *name, unsigned int val, sem_t **sem)
{
	sem_unlink(name);
	*sem = sem_open(name, O_CREAT, 0, val);
	if (!*sem)
	{
		ft_putstr_fd(ERR_INIT_SEM, STDERR_FILENO);
		return (true);
	}
	return (false);
}

bool	init_semaphores(t_table *table)
{
	return (init_semaphore(SEM_NAME_DIE_TIME, 1, &table->common.die_time_sem)
		|| init_semaphore(SEM_NAME_FORKS, table->n_philo % 2,
			&table->common.forks_sem)
		|| init_semaphore(SEM_NAME_LOCK, 0, &table->common.lock_sem));
}
