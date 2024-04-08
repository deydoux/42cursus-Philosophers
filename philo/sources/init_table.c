/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:48:19 by deydoux           #+#    #+#             */
/*   Updated: 2024/04/08 17:42:12 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	safe_atos(char *str, size_t *n)
{
	size_t	tmp;

	tmp = 0;
	*n = 0;
	while ('0' <= *str && *str <= '9')
	{
		tmp = tmp * 10 + *str++ - '0';
		if (*n != tmp / 10)
			return (true);
		*n = tmp;
	}
	return (*str != 0);
}

bool	init_philo(t_table *table)
{
	size_t	i;

	table->philo = ft_calloc(table->seats, sizeof(*table->philo));
	if (!table->philo)
	{
		ft_putstr_fd(ERR_ALLOC_PHILO, STDERR_FILENO);
		return (true);
	}
	i = 0;
	while (i < table->seats)
	{
		if (pthread_mutex_init(&table->philo[i++].fork.mutex, NULL))
		{
			ft_putstr_fd(ERR_MUTEX_INIT, STDERR_FILENO);
			return (true);
		}
	}
	return (false);
}

bool	init_table(int argc, char **argv, t_table *table)
{
	ft_bzero(table, sizeof(*table));
	table->diet = argc == 6;
	if (MIN_ARGC > argc || argc > MAX_ARGC
		|| safe_atos(argv[1], &table->seats)
		|| safe_atos(argv[2], &table->time.die)
		|| safe_atos(argv[3], &table->time.eat)
		|| safe_atos(argv[4], &table->time.sleep)
		|| (table->diet && safe_atos(argv[5], &table->max_bowls)))
	{
		ft_putstrs_fd((t_strs){"Usage: ", argv[0], USAGE, NULL}, STDERR_FILENO);
		return (true);
	}
	return (false);
}
