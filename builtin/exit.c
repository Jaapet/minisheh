/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 18:01:13 by ggualerz          #+#    #+#             */
/*   Updated: 2023/07/09 18:08:28 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	ft_builtin_exit(t_ms *ms, char *cmd)
{
	free(ms); //free ms a faire si le temps
	return(exit(ft_atoi(cmd)));
}
