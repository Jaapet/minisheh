/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:24:35 by ggualerz          #+#    #+#             */
/*   Updated: 2023/06/14 17:22:14 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static	void	ft_printf_pflag_digits(const char *s, t_flag *flag)
{
	size_t	i;

	i = 0;
	while (!(ft_char_is_set(s[i], FLAG_CONV_LIST)) && s[i])
	{
		if (ft_isdigit(s[i]))
		{
			if (s[i] == '0' && flag->min_wide == 0 && flag->precision == 0)
				flag->pad_zero = 1;
			if (s[i - 1] != '.' && flag->min_wide == 0)
				flag->min_wide = ft_atoi(s + i);
			if (s[i - 1] == '.' && flag->precision == 0)
				flag->precision = ft_atoi(s + i);
		}
		i++;
	}
}

static	void	ft_printf_pflag_others(const char *s, t_flag *flag)
{
	size_t	i;

	i = 0;
	while (!(ft_char_is_set(s[i], FLAG_CONV_LIST)) && s[i])
	{
		if (s[i] == '-')
			flag->left_allign = 1;
		if (s[i] == '+')
			flag->plus = 1;
		if (s[i] == ' ')
			flag->space = 1;
		if (s[i] == '#')
			flag->hastag = 1;
		i++;
	}
}

static int	ft_printf_pflag(const char *s, t_flag *f)
{
	size_t	i;

	i = 1;
	ft_printf_pflag_digits(s + i, f);
	ft_printf_pflag_others(s + i, f);
	while (!(ft_char_is_set(s[i], FLAG_CONV_LIST)) && s[i])
		i++;
	f->conv = s[i];
	return (i);
}

static size_t	ft_printf_flag(va_list *args, t_flag *flag)
{
	if (flag->conv == 'd' || flag->conv == 'i')
		return (ft_printf_d(va_arg(*args, int), *flag));
	if (flag->conv == 'c')
		return (ft_printf_c(va_arg(*args, int), *flag));
	if (flag->conv == 's')
		return (ft_printf_s(va_arg(*args, char *), *flag));
	if (flag->conv == 'x' || flag->conv == 'X')
		return (ft_printf_x(va_arg(*args, unsigned int), *flag));
	if (flag->conv == 'p')
		return (ft_printf_p(va_arg(*args, uintptr_t), *flag));
	if (flag->conv == 'u')
		return (ft_printf_u(va_arg(*args, unsigned int), *flag));
	if (flag->conv == '%')
		return (ft_printf_c('%', *flag));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	size_t	i;
	size_t	count_char;
	t_flag	f;

	i = 0;
	count_char = 0;
	va_start (args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			ft_bzero(&f, sizeof(t_flag));
			i += ft_printf_pflag(s + i, &f);
			count_char += ft_printf_flag(&args, &f);
		}
		else
		{
			ft_putchar_fd(s[i], 1);
			count_char++;
		}
		i++;
	}
	va_end(args);
	return (count_char);
}
