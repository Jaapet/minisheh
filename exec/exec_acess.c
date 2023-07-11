/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_acess.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 15:48:46 by ggualerz          #+#    #+#             */
/*   Updated: 2023/07/09 15:57:57 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static char *ft_cmd_in_path(char *cmd, char **path)
{
	size_t	i;
	char	*temp_str;
	char	*temp_cmd;

	i = 0;
	while (path[i])
	{
		temp_str = ft_strjoin(path[i], "/");
		temp_cmd = ft_strjoin(temp_str, cmd);
		free(temp_str);
		if (access(temp_cmd, X_OK) == 0)
			return (temp_cmd);
		free(temp_cmd);
		i++;
	}
	ft_printf_err(cmd, NULL, "command not found");
	return (NULL);
	// ft_exit(ERR_CMD_NOT_FOUND, ms);
}
static void ft_is_builtin(t_exe *curr_exe)
{
	char *temp_str;

	temp_str = curr_exe->cmd[0];
	if ((ft_strncmp(temp_str, "echo", 5) == 0)
	|| (ft_strncmp(temp_str, "env", 4) == 0)
	|| (ft_strncmp(temp_str, "pwd", 4) == 0))
	{
		curr_exe->is_builtin = TRUE;
		curr_exe->env_related = FALSE;
	}
	else if ((ft_strncmp(temp_str, "export", 7) == 0)
	|| (ft_strncmp(temp_str, "cd", 3) == 0)
	|| (ft_strncmp(temp_str, "unset", 6) == 0)
	|| (ft_strncmp(temp_str, "exit", 5) == 0))
	{
		curr_exe->is_builtin = TRUE;
		curr_exe->env_related = TRUE;
	}
	// else
	// {
	// 	curr_exe->is_builtin = FALSE;
	// 	curr_exe->env_related = FALSE;
	// }
}
static void	ft_parse_cmd(t_exe *curr_exe, char **path)
{
	char *temp_cmd;
	char *to_lower_cmd;

	temp_cmd = NULL;
	to_lower_cmd = NULL;
	to_lower_cmd = ft_str_tolower(curr_exe->cmd[0]);
	// if (out_cmd == NULL)
		// ft_exit(ERR_MALLOC, pipex);
	ft_is_builtin(curr_exe);
	if ( curr_exe->is_builtin == TRUE)
		return (free(to_lower_cmd));
	else if (access(to_lower_cmd, X_OK) == 0)
		return (free(to_lower_cmd));
	else
		temp_cmd = ft_cmd_in_path(to_lower_cmd, path);
	free(to_lower_cmd);
	free(curr_exe->cmd[0]);
	curr_exe->cmd[0] = temp_cmd;
	// if (out_cmd == NULL)
		//ERROR
}
void ft_acess_cmd(t_ms *ms)
{
	t_exe *curr_exe;
	char	**path;

	curr_exe = ms->exe_first;
	path = ft_parse_path(ms);
	while(curr_exe)
	{
		ft_parse_cmd(curr_exe, path);
		curr_exe = curr_exe->next;
	}
	ft_clean_tab(path);
}