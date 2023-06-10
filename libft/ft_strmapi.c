/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 18:20:59 by ggualerz          #+#    #+#             */
/*   Updated: 2023/03/31 19:20:14 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*out_str;
	size_t	i;

	out_str = ft_strdup(s);
	if (out_str == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		out_str[i] = (*f)(i, s[i]);
		i++;
	}
	return (out_str);
}