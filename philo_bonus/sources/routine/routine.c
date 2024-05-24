/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:58:38 by deydoux           #+#    #+#             */
/*   Updated: 2024/05/24 17:17:41 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

void	routine(t_philo philo)
{
	sem_wait(philo.write);
	printf("%zu %zu Hi!\n", philo.id, get_ms_time());
	sem_post(philo.write);
}
