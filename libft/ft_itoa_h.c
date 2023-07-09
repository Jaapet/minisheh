/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_h.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 05:42:25 by ggualerz          #+#    #+#             */
/*   Updated: 2023/06/14 17:20:39 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static char	*ft_add_prefix(char *s, char format)
{
	if (format == 'x')
		return (ft_strjoin_free(ft_strdup("0x"), s));
	if (format == 'X')
		return (ft_strjoin_free(ft_strdup("0X"), s));
	return (NULL);
}

static int	ft_count_digits(unsigned int n)
{
	size_t	digits;

	digits = 1;
	while (n > 15)
	{
		n = n / 16;
		digits++;
	}
	return (digits);
}

char	*ft_itoa_h(unsigned int n, char format, char prefix)
{
	int		digits;
	char	*out_str;
	char	*base;

	if (format == 'x')
		base = ft_strdup("0123456789abcdef");
	else if (format == 'X')
		base = ft_strdup("0123456789ABCDEF");
	else
		return (NULL);
	digits = ft_count_digits(n);
	out_str = ft_calloc(digits + 1, sizeof(char));
	if (out_str == NULL)
		return (NULL);
	digits--;
	while (n >= 0 && digits >= 0)
	{
		out_str[digits] = base[n % 16];
		n = n / 16;
		digits--;
	}
	if (prefix == 1 && !(ft_strlen(out_str) == 1 && out_str[0] == '0'))
		out_str = ft_add_prefix(out_str, format);
	return (free(base), out_str);
}
