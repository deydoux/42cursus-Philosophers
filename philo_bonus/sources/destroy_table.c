/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:18:39 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/06 17:01:28 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_table(t_table *table)
{
	if (table->philo.done_sem)
		while (table->philo.n--)
			sem_wait(table->philo.done_sem);
	if (table->philo.exit_sem)
		sem_post(table->philo.exit_sem);
	while (waitpid(0, NULL, 0) != -1)
		;
	if (!table->pids)
		return ;
	free(table->pids);
	close_sems(table->philo);
}
