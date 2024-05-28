/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 22:04:12 by deydoux           #+#    #+#             */
/*   Updated: 2024/05/28 18:51:16 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

bool	think_routine(t_philo *philo)
{
	return (philo_print(philo, THINK_FORMAT, NULL, false));
}
