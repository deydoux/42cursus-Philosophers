/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 06:24:27 by deydoux           #+#    #+#             */
/*   Updated: 2024/05/24 12:42:33 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	bool	exit_code;
	pid_t	guard_pid;
	t_philo	philo;

	exit_code = init_philo(argc, argv, &philo)
		|| init_sleeper(&philo.sleeper)
		|| init_processes(&philo)
		|| init_guard(philo, &guard_pid);
	printf("%i\n", philo.sleeper);
	// if (exit_code)
	// 	while (philo.id--)
	// 		safe_kill(philo.pids[philo.id]);
	// else
	// 	while (philo.id--)
	// 		waitpid(philo.pids[philo.id], NULL, 0);
	// sem_post(philo.write);
	waitpid(guard_pid, NULL, 0);
	free(philo.pids);
	close_semaphores(philo);
	safe_kill(guard_pid);
	safe_kill(philo.sleeper);
	return (exit_code);
}
