/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:21:32 by ggualerz          #+#    #+#             */
/*   Updated: 2023/07/09 14:16:08 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void	ft_single_node(t_ms *ms)
{
	ft_get_node(ms->exe_first, 0)->fd_i = 0;
	ft_get_node(ms->exe_first, 0)->fd_o = 1;
}

static void ft_node_i(t_ms *ms, size_t i)
{
	if (i == 0)
	{
		ft_get_node(ms->exe_first, 0)->fd_i = STDIN_FILENO;
		ft_get_node(ms->exe_first, 0)->fd_o = ms->pipes[3];
	}
	else if (i == ms->cmd_nb - 1)
	{
		ft_get_node(ms->exe_first, i)->fd_i = ms->pipes[i * 2];
		ft_get_node(ms->exe_first, i)->fd_o = STDOUT_FILENO;
	}
	else
	{
		ft_get_node(ms->exe_first, i)->fd_i = ms->pipes[i * 2];
		ft_get_node(ms->exe_first, i)->fd_o = ms->pipes[i * 2 + 3];
	}
}
//We assume than there is already 1 or more nodes in the list
void	ft_assign_fd(t_ms *ms)
{
	size_t i;

	if (ms->cmd_nb == 1)
		ft_single_node(ms);
	else if (ms->cmd_nb > 1)
	{
		i = 0;
		while (i < ms->cmd_nb)
		{
			ft_node_i(ms, i);
			i++;
		}
	}
}
