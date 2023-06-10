/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 06:00:03 by ggualerz          #+#    #+#             */
/*   Updated: 2023/04/20 07:11:50 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\f' || c == '\n' \
	|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

long	ft_atol(const char *nptr)
{
	long	out;
	int		is_neg;
	size_t	i;

	out = 0;
	i = 0;
	is_neg = 1;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			is_neg = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		out = out * 10 + nptr[i] - '0';
		i++;
	}
	return ((long)(out * is_neg));
}
