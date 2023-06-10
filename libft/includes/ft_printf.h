/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:23:40 by ggualerz          #+#    #+#             */
/*   Updated: 2023/04/19 06:49:47 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

# define FLAG_CONV_LIST "cspdiuxX%"

int		ft_printf(const char *s, ...);
int		ft_char_is_set(char c, char *s);

typedef struct s_flag
{
	char	conv;
	size_t	min_wide;
	size_t	precision;
	char	left_allign;
	char	pad_zero;
	char	hastag;
	char	plus;
	char	space;
}	t_flag;

/* PROCESS FLAGS************************************************************* */

size_t	ft_printf_d(int n, t_flag f);
size_t	ft_printf_c(int c, t_flag f);
size_t	ft_printf_s(char *s, t_flag f);
size_t	ft_printf_x(unsigned int n, t_flag f);
size_t	ft_printf_u(unsigned int n, t_flag f);
size_t	ft_printf_p(uintptr_t n, t_flag f);

/* UTILS********************************************************************* */

char	*ft_new_pad_str(char padc, size_t len);

/* VARIANTES***************************************************************** */

void	ft_putstr_stdout(void *s);
size_t	ft_strchr_i(const char *s, int c);

#endif