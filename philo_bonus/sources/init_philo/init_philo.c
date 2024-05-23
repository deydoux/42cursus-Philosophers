/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:55:47 by deydoux           #+#    #+#             */
/*   Updated: 2024/05/23 16:01:41 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_philo.h"

bool	init_philo(int argc, char **argv, t_philo *philo)
{
	ft_bzero(philo, sizeof(*philo));
	return (parse_args(argc, argv, philo) || init_semaphores(philo));
}
