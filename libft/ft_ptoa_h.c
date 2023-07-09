/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoa_h.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 05:42:25 by ggualerz          #+#    #+#             */
/*   Updated: 2023/06/14 17:22:24 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	ft_count_digits(uintptr_t n)
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

char	*ft_ptoa_h(uintptr_t n)
{
	int		digits;
	char	*out_str;
	char	*base;

	base = ft_strdup("0123456789abcdef");
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
	out_str = ft_strjoin_free(ft_strdup("0x"), out_str);
	return (free(base), out_str);
}
