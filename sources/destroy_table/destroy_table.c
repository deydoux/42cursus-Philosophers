/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:18:39 by deydoux           #+#    #+#             */
/*   Updated: 2024/04/22 19:21:56 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "destroy_table.h"

void	destroy_table(t_table table)
{
	destroy_mutexes(table);
	free(table.philos);
}
