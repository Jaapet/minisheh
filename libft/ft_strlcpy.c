/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 20:55:22 by ggualerz          #+#    #+#             */
/*   Updated: 2023/06/14 17:23:16 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while ((src[i] && i < size - 1) && size != 0)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	return (ft_strlen(src));
}
