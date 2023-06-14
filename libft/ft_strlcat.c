/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 21:08:25 by ggualerz          #+#    #+#             */
/*   Updated: 2023/06/14 17:23:13 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	max_dest;
	size_t	max_src;

	max_dest = 0;
	while (dst[max_dest] != '\0' && max_dest < size)
		max_dest++;
	if (size != 0 && size != max_dest)
	{
		i = 0;
		while (src[i] != '\0' && i < size - max_dest - 1)
		{
			dst[max_dest + i] = src[i];
			i++;
		}
		dst[max_dest + i] = '\0';
	}
	max_src = 0;
	while (src[max_src] != '\0')
		max_src++;
	return (max_dest + max_src);
}
