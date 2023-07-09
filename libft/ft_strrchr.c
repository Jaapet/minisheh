/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:47:00 by ggualerz          #+#    #+#             */
/*   Updated: 2023/06/14 17:23:39 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

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
