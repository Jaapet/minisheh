/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 20:16:18 by ggualerz          #+#    #+#             */
/*   Updated: 2023/07/12 21:07:56 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void	ft_dup2(int fd_in, int fd_out, t_ms *ms)
{
	dup2(fd_in, STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	ft_close_pipes(ms);
}

static int	ft_exec_builtin(t_ms *ms, char **cmd)
{
	if (ft_strncmp(cmd[0], "cd", 3) == 0)
		return (ft_cd(cmd[1], ms));
	else if ((ft_strncmp(cmd[0], "echo", 5) == 0))
		return (ft_echo(cmd));
	else if (ft_strncmp(cmd[0], "env", 4) == 0)
		return (ft_env(ms));
	else if (ft_strncmp(cmd[0], "pwd", 4) == 0)
		return (ft_pwd());
	else if (ft_strncmp(cmd[0], "export", 7) == 0)
		return (ft_export(ms, cmd));
	else if (ft_strncmp(cmd[0], "unset", 6) == 0)
		return (ft_unset(ms, cmd));
	else if (ft_strncmp(cmd[0], "exit", 5) == 0)
		return (ft_builtin_exit(ms, cmd), 0);
	return (0);
}

void	ft_fork(t_ms *ms, char **envp, size_t cmd_i)
{
	t_exe	*cur_node;

	cur_node = ft_get_node(ms->exe_first, cmd_i);
	if (cur_node->env_related == TRUE && ms->cmd_nb == 1)
		ft_exec_builtin(ms, cur_node->cmd);
	else 
	{
		cur_node->pid = fork();
		if (cur_node->pid == 0)
		{
			ft_dup2(cur_node->fd_i, cur_node->fd_o, ms);
			if (cur_node->is_builtin == TRUE)
				exit(ft_exec_builtin(ms, cur_node->cmd));
			else if (cur_node->cmd[0] == NULL)
				exit(127);
			else
			{
				execve(cur_node->cmd[0], cur_node->cmd, envp);
			}
			exit (errno);
		}
	}
}
