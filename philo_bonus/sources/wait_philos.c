/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:09:22 by deydoux           #+#    #+#             */
/*   Updated: 2024/05/24 17:29:40 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	wait_philos(void)
{
	int	status;

	while (waitpid(0, &status, 0) != -1)
	{
		if (status)
		{
			kill(0, SIGHUP);
			return (true);
		}
	}
	return (false);
}
