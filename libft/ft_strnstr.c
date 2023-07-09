/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:53:33 by ggualerz          #+#    #+#             */
/*   Updated: 2023/06/14 17:23:34 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)(haystack));
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needle[j])
			j++;
		else
		{
			i = i - j;
			j = 0;
		}
		if (j == ft_strlen(needle))
			return ((char *)(haystack + (i - j + 1)));
		i++;
	}
	return (NULL);
}
