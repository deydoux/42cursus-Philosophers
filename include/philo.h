/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 06:24:34 by deydoux           #+#    #+#             */
/*   Updated: 2024/04/28 21:04:28 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>
# include "philo_utils.h"

# define ERR_INIT_THREADS	"Failed to init threads\n"
# define PHILO_ID_SIZE		21

typedef unsigned int	t_ms;

typedef enum e_philo_state
{
	philo_think,
	philo_eat,
	philo_sleep
}	t_philo_state;

typedef struct s_safe_mutex
{
	bool			initialized;
	pthread_mutex_t	data;
}	t_safe_mutex;

typedef struct s_philo_common
{
	bool			limit_eat;
	bool			ready;
	size_t			must_eat;
	size_t			start_time;
	t_safe_mutex	mutex;
	useconds_t		time_to_eat;
	useconds_t		time_to_die;
	useconds_t		time_to_sleep;
}	t_philo_common;

typedef struct s_philo
{
	char			id[PHILO_ID_SIZE];
	pthread_t		thread;
	size_t			eat_count;
	size_t			i;
	t_philo_common	*common;
	t_philo_state	state;
	t_safe_mutex	*left_fork;
	t_safe_mutex	right_fork;
}	t_philo;

typedef struct s_table
{
	size_t			n_philo;
	t_philo			*philos;
	t_philo_common	common;
}	t_table;

void	destroy_table(t_table table);
size_t	get_ms_time(void);
bool	init_table(int argc, char **argv, t_table *table);
bool	init_threads(t_table *table);
void	*routine(t_philo *philo);

#endif
