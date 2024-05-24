/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 06:24:27 by deydoux           #+#    #+#             */
/*   Updated: 2024/05/24 17:00:59 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	bool	exit_code;
	t_philo	philo;

	exit_code = init_philo(argc, argv, &philo)
		|| init_processes(&philo);
	safe_sem_close(philo.forks);
	safe_sem_close(philo.write);
	free(philo.pids);
	return (exit_code);
}
