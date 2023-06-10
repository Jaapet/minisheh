/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:47:00 by ggualerz          #+#    #+#             */
/*   Updated: 2023/03/29 07:01:32 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	c = (char)c;
	i = ft_strlen(s);
	while (i >= 0 && s[i] != c)
		i--;
	if (i != -1)
		return ((char *)(s + i));
	return (NULL);
}
