/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 20:06:25 by ggualerz          #+#    #+#             */
/*   Updated: 2023/07/12 21:08:27 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	ft_siredir(t_exe *lst, size_t i)
{
	if (lst->fd_i != 0)
		close(lst->fd_i);
	lst->fd_i = open(lst->redir[i].arg, O_RDONLY);
}

void	ft_diredir(t_exe *lst, size_t i)
{
	if (lst->fd_i != 0)
		close(lst->fd_i);
	lst->fd_i = ft_open_heredoc(lst->redir[i].arg);
}

void	ft_soredir(t_exe *lst, size_t i)
{
	if (lst->fd_o != 1)
		close(lst->fd_o);
	lst->fd_o = open(lst->redir[i].arg,
			O_TRUNC | O_CREAT | O_RDWR, 0000644);
}

void	ft_doredir(t_exe *lst, size_t i)
{
	if (lst->fd_o != 1)
		close(lst->fd_o);
	lst->fd_o = open (lst->redir[i].arg,
			O_WRONLY | O_CREAT | O_APPEND, 0000644);
}
