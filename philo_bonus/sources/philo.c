/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 06:24:27 by deydoux           #+#    #+#             */
/*   Updated: 2024/05/23 18:55:29 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	bool	exit_code;
	pid_t	*pids;
	t_philo	philo;

	exit_code = init_philo(argc, argv, &philo)
		|| init_sleeper(&philo.sleeper)
		|| init_processes(philo, &pids);
	sem_post(philo.write);
	safe_sem_close(philo.forks);
	safe_sem_close(philo.write);
	free(pids);
	// check for main process
		kill(philo.sleeper, SIGHUP);
	return (exit_code);
}
