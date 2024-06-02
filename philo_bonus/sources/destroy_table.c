/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:18:39 by deydoux           #+#    #+#             */
/*   Updated: 2024/06/02 22:48:35 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	safe_sem_close(sem_t *sem)
{
	if (sem)
		sem_close(sem);
}

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
	safe_sem_close(table->philo.done_sem);
	safe_sem_close(table->philo.exit_sem);
	safe_sem_close(table->philo.exit_change_sem);
	safe_sem_close(table->philo.forks_sem);
	safe_sem_close(table->philo.write_sem);
}
