/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:55:47 by deydoux           #+#    #+#             */
/*   Updated: 2024/04/16 15:22:48 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_table.h"

static bool	safe_atoull(char *str, unsigned long long *n)
{
	unsigned long long	tmp;

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

bool	parse_args(int argc, char **argv, t_table *table)
{
	ft_bzero(table, sizeof(*table));
	table->limit_meals = argc == 6;
	if (MIN_ARGC > argc || argc > MAX_ARGC
		|| safe_atoull(argv[1], &table->size)
		|| safe_atoull(argv[2], &table->time.die)
		|| safe_atoull(argv[3], &table->time.eat)
		|| safe_atoull(argv[4], &table->time.sleep)
		|| (table->limit_meals && safe_atoull(argv[5], &table->max_meals)))
	{
		ft_putstrs_fd((t_strs){"Usage: ", argv[0], USAGE, NULL}, STDERR_FILENO);
		return (true);
	}
	return (false);
}
