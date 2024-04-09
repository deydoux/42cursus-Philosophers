/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:54:52 by deydoux           #+#    #+#             */
/*   Updated: 2024/04/09 13:17:06 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_TABLE_H
# define INIT_TABLE_H

# include "philo.h"

# define ERR_INIT_MUTEXES	"Failed to init mutexes\n"
# define ERR_INIT_PHILOS	"Failed to init philos\n"
# define MIN_ARGC		5
# define MAX_ARGC		6
# define USAGE			" number_of_philosophers time_to_die time_to_eat \
time_to_sleep [number_of_times_each_philosopher_must_eat]\n"

bool	init_mutexes(t_table *table);
bool	init_philos(t_table *table);
bool	parse_args(int argc, char **argv, t_table *table);

#endif
