/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:52:06 by deydoux           #+#    #+#             */
/*   Updated: 2024/04/19 17:40:28 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_table.h"

static void	init_philo_id(size_t n, char *id)
{
	size_t	tmp_n;
	size_t	len;

	if (!++n)
	{
		ft_strlcpy(id, MAX_PHILO_ID, PHILO_ID_SIZE);
		return ;
	}
	tmp_n = n;
	len = 0;
	while (tmp_n)
	{
		tmp_n /= 10;
		len++;
	}
	id[len] = 0;
	while (len--)
	{
		id[len] = n % 10 + '0';
		n /= 10;
	}
}

static void	init_philo(t_table *table, size_t i)
{
	init_philo_id(i, table->philos[i].id);
	table->philos[i].left_fork = &table->philos[(i + 1) % table->n_philo]
		.right_fork;
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
