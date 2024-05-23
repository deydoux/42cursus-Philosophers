/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 12:15:56 by deydoux           #+#    #+#             */
/*   Updated: 2024/05/23 12:16:16 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_philo.h"

static bool	safe_atos(char *str, size_t *n)
{
	size_t	tmp;

	tmp = 0;
	*n = 0;
	while ('0' <= *str && *str <= '9')
	{
		tmp = tmp * 10 + *str++ - '0';
		if (tmp < *n)
		{
			ft_putstr_fd(ERR_PARSE_SIZE, STDERR_FILENO);
			return (true);
		}
		*n = tmp;
	}
	if (*str != 0)
	{
		ft_putstr_fd(USAGE, STDERR_FILENO);
		return (true);
	}
	return (false);
}

static bool	parse_time(char *str, useconds_t *usec)
{
	size_t	n;

	if (safe_atos(str, &n))
		return (true);
	*usec = n * 1000;
	if (*usec < n)
	{
		ft_putstr_fd(ERR_PARSE_USEC, STDERR_FILENO);
		return (true);
	}
	return (false);
}

bool	parse_args(int argc, char **argv, t_philo *philo)
{
	if (MIN_ARGC > argc || argc > MAX_ARGC)
	{
		ft_putstr_fd(USAGE, STDERR_FILENO);
		return (true);
	}
	philo->limit_eat = argc == 6;
	return (safe_atos(argv[1], &philo->n)
		|| parse_time(argv[2], &philo->time_to_die)
		|| parse_time(argv[3], &philo->time_to_eat)
		|| parse_time(argv[4], &philo->time_to_sleep)
		|| (philo->limit_eat
			&& safe_atos(argv[5], &philo->must_eat)));
}
