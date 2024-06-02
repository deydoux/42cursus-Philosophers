/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sems.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 07:45:31 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/02 19:06:51 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_philo.h"

static bool	init_sem(char *name, unsigned int val, sem_t **sem)
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

bool	init_sems(t_philo *philo)
{
	return (init_sem(SEM_NAME_EXIT, 0, &philo->exit_sem)
		|| init_sem(SEM_NAME_FORKS, philo->n % 2, &philo->forks_sem)
		|| init_sem(SEM_NAME_WRITE, 1, &philo->write_sem));
}
