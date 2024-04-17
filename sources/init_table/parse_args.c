/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:55:47 by deydoux           #+#    #+#             */
/*   Updated: 2024/04/17 15:14:37 by deydoux          ###   ########.fr       */
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
		|| safe_atos(argv[1], &table->size)
		|| safe_atos(argv[2], &table->time.die)
		|| safe_atos(argv[3], &table->time.eat)
		|| safe_atos(argv[4], &table->time.sleep)
		|| (table->limit_meals && safe_atos(argv[5], &table->max_meals)))
	{
		putstrs_fd((t_strs){"Usage: ", argv[0], USAGE, NULL}, STDERR_FILENO);
		return (true);
	}
	return (false);
}
