/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:50:56 by deydoux           #+#    #+#             */
/*   Updated: 2024/05/30 15:41:05 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROUTINE_H
# define ROUTINE_H

# include "philo.h"

# define EAT_FORMAT		"%zu %zu is eating\n"
# define FORK_FORMAT	"%zu %zu has taken a fork\n"
# define SLEEP_FORMAT	"%zu %zu is sleeping\n"
# define THINK_FORMAT	"%zu %zu is thinking\n"

bool	eat_routine(t_philo *philo);
bool	init_routine(t_philo *philo);
void	philo_sleep(useconds_t time, t_philo *philo);
bool	sleep_routine(t_philo *philo);
bool	think_routine(t_philo *philo);

#endif
