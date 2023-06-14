/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 06:46:48 by ggualerz          #+#    #+#             */
/*   Updated: 2023/06/14 17:21:47 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static size_t	ft_(char *s)
{
	size_t	out;

	out = ft_strlen(s);
	free (s);
	return (out);
}

size_t	ft_printf_c(int c, t_flag f)
{
	char	*ps;

	c = (char)c;
	if (f.min_wide > 0 && (int)(f.min_wide - 1) > 0)
	{
		ps = ft_new_pad_str(' ', f.min_wide - 1);
		if (f.left_allign == 1 && f.pad_zero == 0)
			return (ft_putchar_fd(c, 1), ft_putstr_fd(ps, 1), ft_(ps) + 1);
		else
			return (ft_putstr_fd(ps, 1), ft_putchar_fd(c, 1), ft_(ps) + 1);
	}
	else
		return (ft_putchar_fd(c, 1), 1);
}
