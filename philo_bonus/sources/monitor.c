/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:29:29 by deydoux           #+#    #+#             */
/*   Updated: 2024/05/30 16:43:48 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*get_dying_philo(t_table *table, size_t	*die_time)
{
	size_t	i;
	t_philo	*dying_philo;

	i = 0;
	dying_philo = &table->philos[0];
	sem_wait(table->common.die_time_sem);
	while (++i < table->n_philo)
		if (table->philos[i].die_time < dying_philo->die_time)
			dying_philo = &table->philos[i];
	*die_time = dying_philo->die_time;
	sem_post(table->common.die_time_sem);
	return (dying_philo);
}

void	monitor(t_table *table)
{
	size_t	die_time;
	size_t	time;
	t_philo	*philo;

	usleep(table->common.time_to_die / 2);
	while (true)
	{
		philo = get_dying_philo(table, &die_time);
		time = get_ms_time();
		if (time < die_time)
			usleep(die_time - time);
		sem_wait(table->common.die_time_sem);
		if (philo_print(philo, NULL, NULL))
			break ;
		sem_post(table->common.die_time_sem);
	}
	sem_post(table->common.die_time_sem);
}
