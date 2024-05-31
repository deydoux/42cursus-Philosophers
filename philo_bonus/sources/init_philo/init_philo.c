/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 09:17:22 by deydoux           #+#    #+#             */
/*   Updated: 2024/05/31 10:17:29 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_philo.h"

bool	init_philo(int argc, char **argv, t_philo *philo)
{
	return (parse_args(argc, argv, philo) || init_sems(philo));
}
