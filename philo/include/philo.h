/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 06:24:34 by deydoux           #+#    #+#             */
/*   Updated: 2024/04/09 13:17:00 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include "philo_utils.h"

# define ERR_PUTSTRS_FD	"putstrs_fd: Cannot allocate memory\n"

typedef const char	*t_strs[];

typedef struct s_philo_time
{
	size_t	die;
	size_t	eat;
	size_t	sleep;
}	t_philo_time;

typedef struct s_fork
{
	bool			used;
	pthread_mutex_t	mutex;
}	t_fork;

typedef struct s_philo
{
	pthread_t	thread;
	t_fork		fork;
}	t_philo;

typedef struct s_table
{
	size_t			seats;
	t_philo_time	time;
	bool			diet;
	size_t			max_bowls;
	size_t			i;
	t_philo			*philo;
	pthread_mutex_t	mutex;
}	t_table;

bool	init_table(int argc, char **argv, t_table *table);
void	ft_putstrs_fd(t_strs strs, int fd);

#endif
