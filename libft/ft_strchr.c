/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:32:05 by ggualerz          #+#    #+#             */
/*   Updated: 2023/03/29 07:09:14 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	if (c == 0)
		return ((char *)(s + ft_strlen(s)));
	c = (char)c;
	i = 0;
	while (s[i] != c && s[i])
		i++;
	if (i != ft_strlen(s))
		return ((char *)(s + i));
	else if (*(char *)(s + i) == c)
		return ((char *)(s + i));
	return (NULL);
}
