/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sleeper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:32:21 by deydoux           #+#    #+#             */
/*   Updated: 2024/05/24 12:44:58 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleeper_routine(void)
{
	while (true)
		sleep(-1);
}

bool	init_sleeper(pid_t *pid)
{
	*pid = fork();
	if (!*pid)
		sleeper_routine();
	if (*pid < 0)
	{
		ft_putstr_fd(ERR_INIT_PROCESS, STDERR_FILENO);
		return (true);
	}
	return (false);
}
