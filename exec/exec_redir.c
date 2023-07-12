/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:11:10 by ggualerz          #+#    #+#             */
/*   Updated: 2023/07/12 20:44:54 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "../builtin/builtin.h"

int	ft_open_heredoc(char *delim)
{
	int		temp_fd;
	char	*buf;

	g_ms->in_heredoc = TRUE;
	g_ms->heredoc_pid = fork();
	if (g_ms->heredoc_pid == 0)
	{
		temp_fd = open("/tmp/.heredoc_minishell",
				O_TRUNC | O_CREAT | O_RDWR, 0000644);
		while (1)
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
		exit(0);
	}
	waitpid(g_ms->heredoc_pid, NULL, 0);
	g_ms->in_heredoc = FALSE;
	return (open("/tmp/.heredoc_minishell", O_RDONLY));
}

static void	ft_group(t_exe *lst, size_t i)
{
	if (lst->redir[i].type == si_redir)
		ft_siredir(lst, i);
	else if (lst->redir[i].type == di_redir)
		ft_diredir(lst, i);
	else if (lst->redir[i].type == so_redir)
		ft_soredir(lst, i);
	else if (lst->redir[i].type == do_redir)
		ft_doredir(lst, i);
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
				ft_group(lst, i);
				i++;
			}
		}
		lst = lst->next;
	}
}
