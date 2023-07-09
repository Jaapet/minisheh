/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 18:07:58 by ggualerz          #+#    #+#             */
/*   Updated: 2023/07/09 17:00:12 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	ft_pwd()
{
	char out_str[PATH_MAX];
	
	getcwd(out_str, PATH_MAX);
	printf("%s\n", out_str);
	return(0);
}