/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 18:07:58 by ggualerz          #+#    #+#             */
/*   Updated: 2023/07/12 19:44:48 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	ft_pwd(void)
{
	char	out_str[PATH_MAX];

	getcwd(out_str, PATH_MAX);
	printf("%s\n", out_str);
	return (0);
}
