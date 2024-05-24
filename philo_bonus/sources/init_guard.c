/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_guard.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:52:43 by deydoux           #+#    #+#             */
/*   Updated: 2024/05/24 12:40:40 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

bool	init_guard(t_philo philo, pid_t *pid)
{
	*pid = fork();
	if (!*pid)
	{
		waitpid(philo.sleeper, NULL, 0);
		printf("I'm here!\n");
		while (philo.id--)
			safe_kill(philo.pids[philo.id]);
		free(philo.pids);
		close_semaphores(philo);
		exit(EXIT_SUCCESS);
	}
	if (*pid < 0)
	{
		ft_putstr_fd(ERR_INIT_PROCESS, STDERR_FILENO);
		return (true);
	}
	return (false);
}
