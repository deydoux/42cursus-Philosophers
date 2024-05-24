/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 06:24:34 by deydoux           #+#    #+#             */
/*   Updated: 2024/05/24 17:01:10 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <fcntl.h>
# include <semaphore.h>
# include <signal.h>
# include <stdbool.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <sys/wait.h>
# include "philo_utils.h"

# define ERR_INIT_PROCESS	"Failed to init processes\n"

typedef struct s_philo
{
	bool		last;
	bool		limit_eat;
	bool		odd;
	pid_t		*pids;
	sem_t		*forks;
	sem_t		*write;
	size_t		eat_count;
	size_t		die_time;
	size_t		id;
	size_t		must_eat;
	size_t		n;
	size_t		start_time;
	useconds_t	time_to_eat;
	useconds_t	time_to_die;
	useconds_t	time_to_sleep;
}	t_philo;

size_t	get_ms_time(void);
bool	init_philo(int argc, char **argv, t_philo *philo);
bool	init_processes(t_philo *philo);
void	routine(t_philo philo);
void	safe_sem_close(sem_t *sem);

#endif
