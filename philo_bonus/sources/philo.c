/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 06:24:27 by deydoux           #+#    #+#             */
/*   Updated: 2024/05/23 17:17:16 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	pid_t	*pids;
	t_philo	philo;

	if (init_philo(argc, argv, &philo)
		|| init_sleeper(&philo.sleeper)
		|| init_processes(philo, &pids))
		return (EXIT_FAILURE);
	sem_post(philo.write);
	waitpid(pids[0], NULL, 0);
	sem_close(philo.forks);
	sem_close(philo.write);
	free(pids);
	return (EXIT_SUCCESS);
}
