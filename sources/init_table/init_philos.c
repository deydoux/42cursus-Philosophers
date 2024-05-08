/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:52:06 by deydoux           #+#    #+#             */
/*   Updated: 2024/05/07 17:37:39 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_table.h"

static void	init_philo(t_table *table, size_t i)
{
	table->philos[i].even = i % 2 == 0 && i != table->n_philo - 1;
	table->philos[i].id = i + 1;
	table->philos[i].left_fork = &table->philos[(i + 1) % table->n_philo]
		.right_fork;
	table->philos[i].right_fork.used = true;
	table->philos[i].common = &table->common;
}

bool	init_philos(t_table *table)
{
	size_t	i;

	table->philos = ft_calloc(table->n_philo, sizeof(*table->philos));
	if (!table->philos)
	{
		ft_putstr_fd(ERR_INIT_PHILOS, STDERR_FILENO);
		return (true);
	}
	i = 0;
	while (i < table->n_philo)
		init_philo(table, i++);
	return (false);
}
