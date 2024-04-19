/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 06:24:34 by deydoux           #+#    #+#             */
/*   Updated: 2024/04/19 17:49:06 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>
# include "philo_utils.h"

# define PHILO_ID_SIZE	21
# define ERR_PUTSTRS_FD	"putstrs_fd: Cannot allocate memory\n"

typedef const char	*t_strs[];

typedef enum e_philo_state
{
	philo_think = 0,
	philo_eat = 1,
	philo_sleep = 2
}	t_philo_state;

typedef struct s_philo_common
{
	bool			limit_eat;
	bool			ready;
	size_t			must_eat;
	size_t			start_time;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	pthread_mutex_t	mutex;
}	t_philo_common;

typedef struct s_philo
{
	char			id[PHILO_ID_SIZE];
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	right_fork;
	pthread_t		thread;
	size_t			eat_count;
	t_philo_common	*common;
	t_philo_state	state;
}	t_philo;

typedef struct s_table
{
	size_t			n_philo;
	t_philo			*philos;
	t_philo_common	common;
}	t_table;

size_t	get_ms_time(void);
bool	init_table(int argc, char **argv, t_table *table);
bool	init_threads(t_table *table);
void	putstrs_fd(t_strs strs, int fd);
void	*routine(t_philo *philo);

#endif
