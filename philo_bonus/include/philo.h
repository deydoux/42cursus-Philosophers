/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 06:24:34 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/02 19:08:11 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <sys/time.h>
# include <sys/wait.h>
# include "philo_utils.h"

# define ERR_INIT_PROCESSES	"Failed to init processes\n"
# define ERR_INIT_THREADS	"Failed to init threads\n"
# define FORMAT_DIE			"%zu %zu died\n"
# define FORMAT_EAT			"%zu %zu is eating\n"
# define FORMAT_FORK		"%zu %zu has taken a fork\n"
# define FORMAT_SLEEP		"%zu %zu is sleeping\n"
# define FORMAT_THINK		"%zu %zu is thinking\n"

typedef struct s_philo
{
	_Atomic size_t	die_time;
	bool			limit_eat;
	pthread_t		thread;
	sem_t			*exit_sem;
	sem_t			*forks_sem;
	sem_t			*write_sem;
	size_t			id;
	size_t			start_time;
	unsigned int	eat_count;
	unsigned int	must_eat;
	unsigned int	n;
	useconds_t		time_to_die;
	useconds_t		time_to_eat;
	useconds_t		time_to_sleep;
}	t_philo;

typedef struct s_table
{
	pid_t	*pids;
	t_philo	philo;
}	t_table;

void	destroy_table(t_table *table);
size_t	get_ms_time(void);
bool	init_philo(int argc, char **argv, t_philo *philo);
bool	init_processes(t_table *table);
void	init_thread(t_philo *philo);
void	philo_exit(int status, t_philo *philo);
void	philo_print(t_philo *philo, char *format, size_t *time_ptr);
void	*routine(t_philo *philo);

#endif
