/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 20:16:18 by ggualerz          #+#    #+#             */
/*   Updated: 2023/07/11 19:21:01 by ggualerz         ###   ########.fr       */
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
static int ft_exec_builtin(t_ms *ms, char **cmd)
{
	ft_putstr_fd("\nIS_BUILTIN\n",2);
	if(ft_strncmp(cmd[0], "cd", 3)== 0)
		return(ft_cd(cmd[1], ms));
	else if((ft_strncmp(cmd[0], "echo", 5) == 0))
		return(ft_echo(cmd));
	else if (ft_strncmp(cmd[0], "env", 4) == 0)
		return (ft_env(ms));
	else if (ft_strncmp(cmd[0], "pwd", 4) == 0)
		return (ft_pwd());
	else if (ft_strncmp(cmd[0], "export", 7) == 0)
		return (ft_export(ms, cmd));
	else if (ft_strncmp(cmd[0], "unset", 6) == 0)
		return (ft_unset(ms, cmd));
	else if (ft_strncmp(cmd[0], "exit", 5) == 0)
		return (ft_builtin_exit(ms, cmd[1]), ft_atoi(cmd[0]));
	return (0);
}
void	ft_fork(t_ms *ms, char **envp, size_t cmd_i)
{	
	t_exe	*cur_node;

	cur_node = ft_get_node(ms->exe_first, cmd_i);
	if (cur_node->env_related == TRUE && ms->cmd_nb == 1)
		ft_exec_builtin(ms, cur_node->cmd);
	else {
		g_ms->in_exec = TRUE;
		cur_node->pid = fork();
		// if (p->pid[cmd_i] < 0)
		// 	ft_exit(ERR_FORK, p);
		if (cur_node->pid == 0)
		{
			ft_dup2(cur_node->fd_i, cur_node->fd_o, ms);
			if (cur_node->is_builtin == TRUE)
				exit(ft_exec_builtin(ms, cur_node->cmd));
			else
			{
				execve(cur_node->cmd[0], cur_node->cmd, envp);
			}
			return (perror("perror"));
		}	
	}
}
