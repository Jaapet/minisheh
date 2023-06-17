/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 20:16:18 by ggualerz          #+#    #+#             */
/*   Updated: 2023/06/11 22:03:28 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void	ft_dup2(int fd_in, int fd_out, t_ms *ms)
{
	dup2(fd_in, STDIN_FILENO);//to remove
	// if (dup2(fd_in, STDIN_FILENO) < 0)
	// 	ft_exit(ERR_DUP, ms);
	dup2(fd_out, STDOUT_FILENO);// to remove
	// if (dup2(fd_out, STDOUT_FILENO) < 0)
	// 	ft_exit(ERR_DUP, ms);
	ft_close_pipes(ms);
}
void	ft_fork(t_ms *ms, char **envp, size_t cmd_i)
{	
	t_node	*cur_node;

	cur_node = ft_get_node(ms->node_lst, cmd_i);
	cur_node->pid = fork();
	// if (p->pid[cmd_i] < 0)
	// 	ft_exit(ERR_FORK, p);
	if (cur_node->pid == 0)
	{
		ft_dup2(cur_node->fd_i, cur_node->fd_o, ms);
		execve(cur_node->cmd[0], cur_node->cmd, envp);
		// return (perror("execve"), exit(0));
	}	
}
