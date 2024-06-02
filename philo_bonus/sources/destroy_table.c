/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:18:39 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/02 19:07:25 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	safe_kill(pid_t pid)
{
	if (pid > 0)
		kill(pid, SIGHUP);
}

void	destroy_table(t_table *table)
{
	if (!table->pids)
		return ;
	while (--table->philo.id)
		safe_kill(table->pids[table->philo.id - 1]);
	free(table->pids);
	sem_close(table->philo.exit_sem);
	sem_close(table->philo.forks_sem);
	sem_close(table->philo.write_sem);
}
