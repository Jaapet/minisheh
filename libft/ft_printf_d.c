/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 05:25:17 by ggualerz          #+#    #+#             */
/*   Updated: 2023/06/14 17:21:51 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static size_t	ft_strlen_free(char *s)
{
	size_t	out;

	out = ft_strlen(s);
	free (s);
	return (out);
}

static size_t	ft_putsign(t_flag f, int n)
{
	if (n < 0)
		return (ft_putchar_fd('-', 1), 1);
	if (f.plus == 1)
		return (ft_putchar_fd('+', 1), 1);
	if (f.space == 1)
		return (ft_putchar_fd(' ', 1), 1);
	return (0);
}

size_t	ft_printf_d(int n, t_flag f)
{
	char	*i_str;
	char	*p_str;
	char	*o_str;
	size_t	char_added;

	i_str = ft_itoa_sign(n, 0, 0);
	if (i_str == NULL)
		return (0);
	char_added = ft_putsign(f, n);
	if (f.min_wide > 0 && (int)(f.min_wide - (int)ft_strlen(i_str)) > 0)
	{
		f.min_wide -= char_added;
		if (f.pad_zero == 1 && f.left_allign == 0)
			p_str = ft_new_pad_str('0', f.min_wide - ft_strlen(i_str));
		else
			p_str = ft_new_pad_str(' ', f.min_wide - ft_strlen(i_str));
		if (f.left_allign == 1 && f.pad_zero == 0)
			o_str = ft_strjoin_free(i_str, p_str);
		else
			o_str = ft_strjoin_free(p_str, i_str);
		return (ft_putstr_fd(o_str, 1), ft_strlen_free(o_str) + char_added);
	}
	else
		return (ft_putstr_fd(i_str, 1), ft_strlen_free(i_str) + char_added);
}
