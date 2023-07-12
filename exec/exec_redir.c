/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:11:10 by ggualerz          #+#    #+#             */
/*   Updated: 2023/07/12 18:39:56 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "../builtin/builtin.h"

// static char *ft_replace_var_hd(char *str_cpy, char *var_val)
// {
// 	char *new_str_cpy;
// 	char *tmp;
	
// 	tmp = ft_strdup(str_cpy);
// 	*(ft_strchr(tmp, '$')) = '\0';
// 	new_str_cpy = ft_strjoin(tmp, var_val);
// 	free(tmp);
// 	free(str_cpy);
// 	free(var_val);
// 	return (new_str_cpy);
// }

// static char *ft_expand_heredoc(char *str)
// {
// 	char *var_val;
// 	char *str_cpy;
// 	char *var_name;
	
// 	str_cpy = ft_strdup(str);
// 	while(ft_strchr(str_cpy, '$') != NULL)
// 	{
// 		var_name = ft_isolate_var(str_cpy);
// 		var_val = ft_get_env_value( g_ms->envp, var_name);
// 		str_cpy = ft_replace_var_hd(str_cpy, var_val);
// 		free(var_name);
// 	}
// 	free (str);
// 	HELP ME
// 	return (str_cpy);

// }

static int ft_open_heredoc(char *delim)
{
	int	temp_fd;
	char	*buf;
	
	g_ms->in_heredoc = TRUE;
	g_ms->heredoc_pid = fork();
	if (g_ms->heredoc_pid == 0)
	{
		temp_fd = open("/tmp/.heredoc_minishell", O_CREAT | O_WRONLY | O_TRUNC, 0000644);
		//IN HEREDOC TRUE
		while(1)
		{
			write(1, "heredoc> ", 10);
			buf = get_next_line(0);
			if (ft_strncmp(delim, buf, ft_strlen(delim)) == 0)
				break ;
			// buf = ft_expand_heredoc(buf);
			write(temp_fd, buf, ft_strlen(buf));
			free(buf);
		}
		free(buf);
		close(temp_fd);
	}
	waitpid(g_ms->heredoc_pid,NULL,0);
	g_ms->in_heredoc = FALSE;
	return(open("/tmp/.heredoc_minishell", O_RDONLY));
	return (0);
}

void	ft_set_redir(t_ms *ms)
{
	t_exe	*lst;
	size_t	i;

	i = 0;
	lst = ms->exe_first;
	while (lst)
	{
		if (lst->redir == NULL)
			return ;
		if (lst->redir->type != undefined)
		{
			while ((lst->redir + i)->type != 0)
			{
				if (lst->redir[i].type == si_redir)
				{
					if (lst->fd_i != 0)
						close(lst->fd_i);
					lst->fd_i = open(lst->redir[i].arg, FLAG_INFILE_STD);
				}
				else if (lst->redir[i].type == di_redir)
				{
					if (lst->fd_i != 0)
						close(lst->fd_i);
					lst->fd_i = ft_open_heredoc(lst->redir[i].arg); //HERE_DOC
				}
				else if (lst->redir[i].type == so_redir)
				{
					if (lst->fd_o != 1)
						close(lst->fd_o);
					lst->fd_o = open(lst->redir[i].arg, FLAG_OUTFILE_STD, 0000644);
				}
				else if (lst->redir[i].type == do_redir)
				{
					if (lst->fd_o != 1)
						close(lst->fd_o);
					lst->fd_o = open (lst->redir[i].arg, FLAG_OUTFILE_APPEND, 0000644);
				}
				i++;
			}
		}
		lst = lst->next;
	}
}
