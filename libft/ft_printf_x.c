/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 20:18:45 by ggualerz          #+#    #+#             */
/*   Updated: 2023/06/14 17:22:18 by ndesprez         ###   ########.fr       */
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

size_t	ft_printf_x(unsigned int n, t_flag f)
{
	char	*i_str;
	char	*p_str;
	char	*o_str;

	i_str = ft_itoa_h(n, f.conv, f.hastag);
	if (i_str == NULL)
		return (0);
	if (f.min_wide > 0 && (int)(f.min_wide - (int)ft_strlen(i_str)) > 0)
	{
		if (f.pad_zero == 1 && f.left_allign == 0)
			p_str = ft_new_pad_str('0', f.min_wide - ft_strlen(i_str));
		else
			p_str = ft_new_pad_str(' ', f.min_wide - ft_strlen(i_str));
		if (f.left_allign == 1 && f.pad_zero == 0)
			o_str = ft_strjoin_free(i_str, p_str);
		else
			o_str = ft_strjoin_free(p_str, i_str);
		return (ft_putstr_fd(o_str, 1), ft_strlen_free(o_str));
	}
	else
		return (ft_putstr_fd(i_str, 1), ft_strlen_free(i_str));
}
