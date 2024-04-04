/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 06:24:34 by deydoux           #+#    #+#             */
/*   Updated: 2024/04/04 17:27:45 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdbool.h>

# define MIN_ARGC		5
# define MAX_ARGC		6
# define USAGE			"%s number_of_philosophers time_to_die time_to_eat\
time_to_sleep [number_of_times_each_philosopher_must_eat]\n"

typedef struct s_philos
{
	unsigned long	n;
	unsigned long	die;
	unsigned long	eat;
	unsigned long	sleep;
	unsigned long	max_eat;
}	t_philos;

size_t	ft_strlen(char *str);

#endif
