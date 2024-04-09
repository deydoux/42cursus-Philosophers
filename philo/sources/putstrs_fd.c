/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstrs_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:22:27 by deydoux           #+#    #+#             */
/*   Updated: 2024/04/09 13:16:28 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static size_t	strslen(t_strs strs)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	while (strs[i])
		size += ft_strlen(strs[i++]);
	return (size);
}

static char	*join_strs(t_strs strs)
{
	size_t	size;
	char	*str;
	size_t	i;

	size = sizeof(char) * (strslen(strs) + 1);
	str = malloc(size);
	if (!str)
		return (NULL);
	*str = 0;
	i = 0;
	while (strs[i])
		ft_strlcat(str, strs[i++], size);
	return (str);
}

void	ft_putstrs_fd(t_strs strs, int fd)
{
	char	*str;

	str = join_strs(strs);
	if (!str)
		return (ft_putstr_fd(ERR_PUTSTRS_FD, STDERR_FILENO));
	ft_putstr_fd(str, fd);
	free(str);
}
