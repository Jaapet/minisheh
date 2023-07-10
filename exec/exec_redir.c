/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:11:10 by ggualerz          #+#    #+#             */
/*   Updated: 2023/07/10 22:38:03 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

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
