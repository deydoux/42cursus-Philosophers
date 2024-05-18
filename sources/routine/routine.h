/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:50:56 by deydoux           #+#    #+#             */
/*   Updated: 2024/05/18 23:24:11 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROUTINE_H
# define ROUTINE_H

# include <stdio.h>
# include "philo.h"

# define DIE_FORMAT		"%zu %zu died\n"
# define EAT_FORMAT		"%zu %zu is eating\n"
# define FORK_FORMAT	"%zu %zu has taken a fork\n"
# define SLEEP_FORMAT	"%zu %zu is sleeping\n"
# define THINK_FORMAT	"%zu %zu is thinking\n"

bool	eat(t_philo *philo);
bool	philo_print(t_philo *philo, char *format, size_t *time_ptr);
void	philo_sleep(useconds_t time, t_philo *philo);
bool	sleep_routine(t_philo *philo);
bool	think(t_philo *philo);

#endif
