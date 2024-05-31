/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 06:24:27 by deydoux           #+#    #+#             */
/*   Updated: 2024/05/31 21:13:58 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	bool	error;
	int		status;
	t_table	table;

	status = 0;
	ft_bzero(&table, sizeof(table));
	error = init_philo(argc, argv, &table.philo) || init_processes(&table);
	if (!error)
		while (waitpid(0, &status, 0) != -1 && !status)
			;
	destroy_table(&table);
	return (error);
}
