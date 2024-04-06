/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 06:24:34 by deydoux           #+#    #+#             */
/*   Updated: 2024/04/06 16:04:52 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>

# define ERR_PUTSTRS	"ft_putstrs_fd: Cannot allocate memory"
# define MIN_ARGC		5
# define MAX_ARGC		6
# define USAGE			" number_of_philosophers time_to_die time_to_eat\
time_to_sleep [number_of_times_each_philosopher_must_eat]\n"

typedef const char	*t_strs[];

typedef struct s_philos
{
	unsigned long	n;
	unsigned long	die;
	unsigned long	eat;
	unsigned long	sleep;
	unsigned long	max_eat;
}	t_philos;

void	ft_putstr_fd(const char *str, int fd);
void	ft_putstrs_fd(const char **strs, int fd);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);
bool	init_philos(int argc, char **argv, t_philos *philos);

#endif
