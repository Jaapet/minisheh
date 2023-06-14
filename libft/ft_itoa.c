/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 05:42:25 by ggualerz          #+#    #+#             */
/*   Updated: 2023/06/14 17:20:48 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	ft_count_digits(int n)
{
	size_t	digits;

	digits = 1;
	if (n < 0)
	{
		digits++;
		n = n * -1;
	}
	while (n > 9)
	{
		n = n / 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	int		digits;
	char	*out_str;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	digits = ft_count_digits(n);
	out_str = ft_calloc(digits + 1, sizeof(char));
	if (out_str == NULL)
		return (NULL);
	out_str[digits] = '\0';
	if (n < 0)
	{
		out_str[0] = '-';
		n = n * -1;
	}
	digits--;
	while (n >= 0 && digits >= 0)
	{
		if (out_str[digits] == '-')
			break ;
		out_str[digits] = n % 10 + '0';
		n = n / 10;
		digits--;
	}
	return (out_str);
}
