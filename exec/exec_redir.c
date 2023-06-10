/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:11:10 by ggualerz          #+#    #+#             */
/*   Updated: 2023/06/10 18:05:03 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	ft_set_redir(t_ms *ms)
{
	t_node	*lst;

	lst = ms->node_lst;
	while (lst)
	{
		if (lst->is_redir == TRUE)
		{
			if (lst->redir_t == RD_I_S)
				lst->fd_i = open(lst->i_file, FLAG_INFILE_STD);
			//else if (lst->redir_t == RD_I_D)
				//ft_heredoc
			if (lst->redir_t == RD_O_S)
				lst->fd_o = open(lst->o_file, FLAG_OUTFILE_STD, 0000644);
			else if (lst->redir_t == RD_O_D)
				lst->fd_o = open (lst->o_file, FLAG_OUTFILE_APPEND, 0000644);
		}
		lst = lst->next;
	}
}
