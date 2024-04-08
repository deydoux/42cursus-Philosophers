/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 12:43:10 by deydoux           #+#    #+#             */
/*   Updated: 2024/04/08 12:43:25 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_utils.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	bytes;
	void	*ptr;

	if (size && nmemb > SIZE_MAX / size)
		return (NULL);
	bytes = nmemb * size;
	ptr = malloc(bytes);
	if (ptr)
		ft_bzero(ptr, bytes);
	return (ptr);
}
