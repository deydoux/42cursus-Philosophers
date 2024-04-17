/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:56:35 by deydoux           #+#    #+#             */
/*   Updated: 2024/04/16 18:19:32 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	init_threads(t_table *table)
{
	size_t	i;

	pthread_mutex_lock(&table->mutex);
	i = 0;
	while (i < table->size)
	{
		pthread_create(&table->philos[i].thread, NULL, (void *)routine,
			&table->philos[i]);
		pthread_detach(table->philos[i].thread);
		i++;
	}
	pthread_mutex_unlock(&table->mutex);
	return (false);
}
