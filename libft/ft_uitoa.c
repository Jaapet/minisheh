/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 05:42:25 by ggualerz          #+#    #+#             */
/*   Updated: 2023/06/14 17:23:57 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	ft_count_digits(unsigned int n)
{
	size_t	digits;

	digits = 1;
	while (n > 9)
	{
		n = n / 10;
		digits++;
	}
	return (digits);
}

char	*ft_uitoa(unsigned int n)
{
	int		digits;
	char	*out_str;

	digits = ft_count_digits(n);
	out_str = ft_calloc(digits + 1, sizeof(char));
	if (out_str == NULL)
		return (NULL);
	digits--;
	while (n >= 0 && digits >= 0)
	{
		out_str[digits] = n % 10 + '0';
		n = n / 10;
		digits--;
	}
	return (out_str);
}
