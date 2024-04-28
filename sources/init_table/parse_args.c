/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:55:47 by deydoux           #+#    #+#             */
/*   Updated: 2024/04/28 20:35:33 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_table.h"

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
			ft_putstr_fd(ERR_PARSE_SIZE_MAX, STDERR_FILENO);
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

static bool	parse_time(char *str, t_ms *ms)
{
	size_t	n;

	if (safe_atos(str, &n))
		return (true);
	if (n > MS_MAX)
	{
		ft_putstr_fd(ERR_PARSE_MS_MAX, STDERR_FILENO);
		return (true);
	}
	*ms = n;
	return (false);
}

bool	parse_args(int argc, char **argv, t_table *table)
{
	if (MIN_ARGC > argc || argc > MAX_ARGC)
	{
		ft_putstr_fd(USAGE, STDERR_FILENO);
		return (true);
	}
	table->common.limit_eat = argc == 6;
	return (safe_atos(argv[1], &table->n_philo)
		|| parse_time(argv[2], &table->common.time_to_die)
		|| parse_time(argv[3], &table->common.time_to_eat)
		|| parse_time(argv[4], &table->common.time_to_sleep)
		|| (table->common.limit_eat
			&& safe_atos(argv[5], &table->common.must_eat)));
}
