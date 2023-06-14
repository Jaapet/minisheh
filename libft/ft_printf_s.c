/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 07:00:10 by ggualerz          #+#    #+#             */
/*   Updated: 2023/06/14 17:22:03 by ndesprez         ###   ########.fr       */
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

size_t	ft_printf_s(char *s, t_flag f)
{
	char	*i_str;
	char	*p_str;
	char	*o_str;

	if (s == NULL)
		return (ft_putstr_fd("(null)", 1), 6);
	if (f.precision != 0)
		i_str = ft_substr(s, 0, f.precision);
	i_str = ft_strdup(s);
	if (i_str == NULL)
		return (0);
	if (f.min_wide > 0 && (int)(f.min_wide - (int)ft_strlen(i_str)) > 0)
	{
		p_str = ft_new_pad_str(' ', f.min_wide - ft_strlen(i_str));
		if (f.left_allign == 1)
			o_str = ft_strjoin_free(i_str, p_str);
		else
			o_str = ft_strjoin_free(p_str, i_str);
		return (ft_putstr_fd(o_str, 1), ft_strlen_free(o_str));
	}
	else
		return (ft_putstr_fd(i_str, 1), ft_strlen_free(i_str));
}
