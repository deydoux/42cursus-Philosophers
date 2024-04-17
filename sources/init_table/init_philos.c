/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:52:06 by deydoux           #+#    #+#             */
/*   Updated: 2024/04/17 15:14:59 by deydoux          ###   ########.fr       */
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

bool	init_philos(t_table *table)
{
	size_t	i;

	table->philos = ft_calloc(table->size, sizeof(*table->philos));
	if (!table->philos)
	{
		ft_putstr_fd(ERR_INIT_PHILOS, STDERR_FILENO);
		return (true);
	}
	i = 0;
	while (i < table->size)
	{
		init_philo_id(i, table->philos[i].id);
		table->philos[i].fork_l = &table->philos[(i + 1) % table->size].fork_r;
		table->philos[i].table_mutex = &table->mutex;
		i++;
	}
	return (false);
}
