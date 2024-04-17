/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 06:24:34 by deydoux           #+#    #+#             */
/*   Updated: 2024/04/17 16:13:33 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include "philo_utils.h"

# define PHILO_ID_SIZE	21
# define ERR_PUTSTRS_FD	"putstrs_fd: Cannot allocate memory\n"

typedef const char	*t_strs[];

typedef struct s_philo_time
{
	size_t	die;
	size_t	eat;
	size_t	sleep;
}	t_philo_time;

typedef struct s_philo
{
	pthread_mutex_t	fork_r;
	pthread_mutex_t	*fork_l;
	char			id[PHILO_ID_SIZE];
	bool			limit_meals;
	size_t			max_meals;
	size_t			meals;
	pthread_mutex_t	*table_mutex;
	pthread_t		thread;
	t_philo_time	time;
}	t_philo;

typedef struct s_table
{
	bool			limit_meals;
	size_t			max_meals;
	pthread_mutex_t	mutex;
	t_philo			*philos;
	size_t			size;
	t_philo_time	time;
}	t_table;

bool	init_table(int argc, char **argv, t_table *table);
bool	init_threads(t_table *table);
void	putstrs_fd(t_strs strs, int fd);
void	*routine(t_philo *philo);

#endif
