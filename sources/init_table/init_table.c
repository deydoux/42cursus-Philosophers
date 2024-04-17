/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:48:19 by deydoux           #+#    #+#             */
/*   Updated: 2024/04/17 16:12:26 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_table.h"

bool	init_table(int argc, char **argv, t_table *table)
{
	return (parse_args(argc, argv, table)
		|| init_philos(table));
}
