/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:52:06 by deydoux           #+#    #+#             */
/*   Updated: 2024/05/19 19:11:26 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_table.h"

static void	init_philo(t_table *table, size_t i)
{
	t_philo	*philo;

	philo = &table->philos[i];
	philo->last = i == table->n_philo - 1;
	philo->even = i % 2 == 0 && !philo->last;
	philo->id = i + 1;
	philo->left_fork = &table->philos[(i + 1) % table->n_philo].right_fork;
	if (philo->even)
	{
		philo->right_fork.taken = true;
		philo->left_fork->taken = true;
	}
	philo->common = &table->common;
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
