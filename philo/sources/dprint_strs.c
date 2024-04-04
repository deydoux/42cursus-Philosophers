/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dprint_strs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:22:27 by deydoux           #+#    #+#             */
/*   Updated: 2024/04/04 17:31:40 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static size_t	strs_size(char **strs)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	while (strs[i])
		size += ft_strlen(strs[i++]);
	return (size);
}

static char	*join_strs(char **strs)
{
	size_t	size;
	char	*str;

	size = strs_size(strs);
	str = malloc(sizeof(char) * size);
}

void	dprint_strs(char **strs)
{
	char	*str;

	str = join_strs(strs);
	if (str)
	{

		free(str);
	}
}
