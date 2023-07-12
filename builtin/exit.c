/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 18:01:13 by ggualerz          #+#    #+#             */
/*   Updated: 2023/07/12 19:15:59 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static size_t ft_strlen_exit(char *cmd)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while(cmd[i] == '0')
		i++;
	while(cmd[i])
	{
		i++;
		j++;
	}
	return (j);
}

static	bool ft_check_exit_arg(char *cmd)
{
	size_t i;

	i = 0;
	if (ft_strlen_exit(cmd) > 10)
		return (FALSE);
	if (ft_atol(cmd) > INT_MAX || ft_atol(cmd) < INT_MIN)
		return (FALSE);
	while (cmd[i])
	{
		if (ft_isdigit(cmd[i]) != 1)
		return (FALSE);
		i++;
	}
	return (TRUE);
}

void	ft_builtin_exit(t_ms *ms, char **cmd)
{
	free(ms); //free ms a faire si le temps
	return(exit(ft_atoi(cmd)));
}
