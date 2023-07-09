/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_sign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 05:42:25 by ggualerz          #+#    #+#             */
/*   Updated: 2023/06/14 17:20:44 by ndesprez         ###   ########.fr       */
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

static char	*ft_format(char *str, char plus_sign, char neg_sign)
{
	char	*temp_str;

	if (str[0] == '-' && neg_sign == 0)
	{
		temp_str = ft_substr(str, 1, ft_strlen (str + 1));
		free (str);
		return (temp_str);
	}
	else if (str[0] != '-' && plus_sign == 1)
	{
		temp_str = ft_strjoin(ft_strdup("+"), str);
		free (str);
		return (temp_str);
	}
	else
		return (str);
}

char	*ft_itoa_sign(int n, char plus_sign, char neg_sign)
{
	int		digits;
	char	*out_str;

	if (n == INT_MIN)
		return (ft_format(ft_strdup("-2147483648"), plus_sign, neg_sign));
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
	return (ft_format(out_str, plus_sign, neg_sign));
}
