/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:48:19 by deydoux           #+#    #+#             */
/*   Updated: 2024/04/04 17:22:16 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	safe_atoul(char *str, unsigned long *n)
{
	unsigned long	tmp;

	tmp = 0;
	*n = 0;
	while ('0' <= *str && str <= '9')
	{
		tmp = tmp * 10 + *str++ - '0';
		if (*n != tmp / 10)
			return (true);
		*n = tmp;
	}
	return (*str != 0);
}

bool	init_philos(int argc, char **argv, t_philos *philos)
{
	if (MIN_ARGC > argc || argc > MAX_ARGC
		|| safe_atoul(argv[1], &philos->n)
		|| safe_atoul(argv[2], &philos->die)
		|| safe_atoul(argv[3], &philos->eat)
		|| safe_atoul(argv[4], &philos->sleep)
		|| (argc == 6 && safe_atoul(argv[6], &philos->max_eat)))
	{

		return (true);
	}
	return (false);
}
