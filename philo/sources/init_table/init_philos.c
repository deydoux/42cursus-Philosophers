/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:52:06 by deydoux           #+#    #+#             */
/*   Updated: 2024/04/09 13:13:37 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_table.h"

bool	init_philos(t_table *table)
{
	table->philo = ft_calloc(table->seats, sizeof(*table->philo));
	if (!table->philo)
	{
		ft_putstr_fd(ERR_INIT_PHILOS, STDERR_FILENO);
		return (true);
	}
	return (false);
}
