/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 06:24:34 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/02 22:36:14 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <fcntl.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <sys/time.h>
# include <sys/wait.h>
# include "philo_utils.h"

# define ERR_INIT_PHILOS		"Failed to init philos\n"
# define ERR_INIT_PROCESSES		"Failed to init processes\n"
# define ERR_INIT_SEM			"Failed to init semaphores\n"
# define ERR_INIT_THREADS		"Failed to init threads\n"
# define ERR_PARSE_TIME			"Time arguments overflowed on ms conversion\n"
# define ERR_SAFE_ATOUI			"Arguments overflowed unsigned int\n"
# define FORMAT_DIE				"%zu %zu died\n"
# define FORMAT_EAT				"%zu %zu is eating\n"
# define FORMAT_FORK			"%zu %zu has taken a fork\n"
# define FORMAT_SLEEP			"%zu %zu is sleeping\n"
# define FORMAT_THINK			"%zu %zu is thinking\n"
# define MAX_ARGC				6
# define MIN_ARGC				5
# define SEM_NAME_DONE			"/philo_done"
# define SEM_NAME_EXIT			"/philo_exit"
# define SEM_NAME_EXIT_CHANGE	"/philo_exit_change"
# define SEM_NAME_FORKS			"/philo_forks"
# define SEM_NAME_WRITE			"/philo_write"
# define USAGE "Usage: ./philo_bonus number_of_philosophers time_to_die\
time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n"

typedef struct s_safe_thread
{
	bool		initialized;
	pthread_t	data;
}	t_safe_thread;

typedef struct s_philo
{
	_Atomic bool	exit;
	_Atomic size_t	die_time;
	bool			limit_eat;
	sem_t			*done_sem;
	sem_t			*exit_sem;
	sem_t			*exit_change_sem;
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

bool	init_philo(int argc, char **argv, t_philo *philo);
bool	init_processes(t_table *table);
bool	init_sems(t_philo *philo);
bool	parse_args(int argc, char **argv, t_philo *philo);
bool	philo_print(t_philo *philo, char *format, size_t *time_ptr);
size_t	get_ms_time(void);
void	*routine(t_philo *philo);
void	destroy_table(t_table *table);
void	init_threads(t_philo *philo);

#endif
