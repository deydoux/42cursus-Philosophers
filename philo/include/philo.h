/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 06:24:34 by deydoux           #+#    #+#             */
/*   Updated: 2024/04/15 18:29:36 by deydoux          ###   ########.fr       */
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
	unsigned long long	die;
	unsigned long long	eat;
	unsigned long long	sleep;
}	t_philo_time;

typedef struct s_fork
{
	bool			used;
	pthread_mutex_t	mutex;
}	t_fork;

typedef struct s_philo
{
	pthread_t			thread;
	t_philo_time		time;
	pthread_mutex_t		*table_mutex;
	char				id[PHILO_ID_SIZE];
	t_fork				fork_r;
	t_fork				*fork_l;
	unsigned long long	meals;
	bool				limit_meals;
	unsigned long long	max_meals;
}	t_philo;

typedef struct s_table
{
	unsigned long long	n;
	t_philo_time		time;
	bool				limit_meals;
	unsigned long long	max_meals;
	t_philo				*philo;
	pthread_mutex_t		mutex;
}	t_table;

bool	init_table(int argc, char **argv, t_table *table);
void	ft_putstrs_fd(t_strs strs, int fd);

#endif
