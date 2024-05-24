/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:52:06 by deydoux           #+#    #+#             */
/*   Updated: 2024/05/24 19:23:01 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_table.h"

static void	init_philo(t_table *table, size_t i)
{
	t_philo	*philo;

	philo = &table->philos[i];
	philo->odd = i % 2;
	philo->id = i + 1;
	philo->left_fork = &table->philos[(i + 1) % table->n_philo].right_fork;
	philo->common = &table->common;
	if (philo->odd)
	{
		philo->right_fork.taken = true;
		philo->left_fork->taken = true;
	}
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
