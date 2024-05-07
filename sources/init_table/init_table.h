/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:54:52 by deydoux           #+#    #+#             */
/*   Updated: 2024/05/07 15:01:59 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_TABLE_H
# define INIT_TABLE_H

# include "philo.h"

# define ERR_INIT_MUTEXES	"Failed to init mutexes\n"
# define ERR_INIT_PHILOS	"Failed to init philos\n"
# define ERR_PARSE_SIZE		"Arguments overflowed size_t\n"
# define ERR_PARSE_USEC		"Time arguments overflowed useconds_t\n"
# define MAX_ARGC			6
# define MIN_ARGC			5
# define USAGE				"Usage: ./philo number_of_philosophers time_to_die \
time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n"

bool	init_mutexes(t_table *table);
bool	init_philos(t_table *table);
bool	parse_args(int argc, char **argv, t_table *table);

#endif
