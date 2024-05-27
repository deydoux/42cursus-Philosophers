/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 06:24:34 by deydoux           #+#    #+#             */
/*   Updated: 2024/05/27 07:33:26 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <semaphore.h>
#include <signal.h>
# include <stdbool.h>
# include <sys/time.h>
# include "philo_utils.h"

# define ERR_INIT_THREADS	"Failed to init threads\n"

typedef struct s_philo_common
{
	bool			exit;
	bool			limit_eat;
	sem_t			*forks_sem;
	sem_t			*lock_sem;
	size_t			must_eat;
	size_t			start_time;
	useconds_t		time_to_eat;
	useconds_t		time_to_die;
	useconds_t		time_to_sleep;
}	t_philo_common;

typedef struct s_safe_thread
{
	bool		initialized;
	pthread_t	data;
}	t_safe_thread;

typedef struct s_philo
{
	bool			odd;
	size_t			die_time;
	size_t			eat_count;
	size_t			id;
	t_philo_common	*common;
	t_safe_thread	thread;
}	t_philo;

typedef struct s_table
{
	size_t			n_philo;
	t_philo			*philos;
	t_philo_common	common;
}	t_table;

void	destroy_table(t_table *table);
size_t	get_ms_time(void);
bool	init_table(int argc, char **argv, t_table *table);
bool	init_threads(t_table *table);
void	*routine(t_philo *philo);

#endif
