/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deydoux <deydoux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 15:48:37 by deydoux           #+#    #+#             */
/*   Updated: 2024/04/08 12:38:43 by deydoux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_utils.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	if (size <= dst_len)
		return (ft_strlen(src) + size);
	src_len = 0;
	while (dst_len + src_len < size - 1 && src[src_len])
	{
		dst[dst_len + src_len] = src[src_len];
		src_len++;
	}
	dst[dst_len + src_len] = 0;
	while (src[src_len])
		src_len++;
	return (dst_len + src_len);
}
