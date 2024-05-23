/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:13:16 by deydoux           #+#    #+#             */
/*   Updated: 2024/05/23 16:01:37 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_PHILO_H
# define INIT_PHILO_H

# include "philo.h"

# define ERR_INIT_SEM	"Failed to init semaphores\n"
# define ERR_PARSE_SIZE	"Arguments overflowed size_t\n"
# define ERR_PARSE_USEC	"Time arguments overflowed useconds_t\n"
# define MAX_ARGC		6
# define MIN_ARGC		5
# define SEM_NAME_FORKS	"/philo_forks"
# define SEM_NAME_WRITE	"/philo_write"
# define USAGE			"Usage: ./philo_bonus number_of_philosophers\
time_to_die time_to_eat time_to_sleep\
[number_of_times_each_philosopher_must_eat]\n"

bool	parse_args(int argc, char **argv, t_philo *philo);
bool	init_semaphores(t_philo *philo);

#endif
