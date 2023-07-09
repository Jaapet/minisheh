/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 06:05:06 by ggualerz          #+#    #+#             */
/*   Updated: 2023/06/14 17:22:11 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_char_is_set(char c, char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (c == s[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_new_pad_str(char padc, size_t len)
{
	char	*out_str;
	size_t	i;

	i = 0;
	out_str = ft_calloc(len + 1, sizeof(char));
	if (out_str == NULL)
		return (NULL);
	while (i < len)
	{
		out_str[i] = padc;
		i++;
	}
	return (out_str);
}
