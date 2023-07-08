/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:11:10 by ggualerz          #+#    #+#             */
/*   Updated: 2023/06/19 17:37:26 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	ft_set_redir(t_ms *ms)
{
	t_node	*lst;
	size_t	i;

	i = 0;
	lst = ms->node_lst;
	while (lst)
	{
		if (lst->redir)
		{
			while (lst->redir + i)
			{
				if (lst->redir[i].type == in_simple)
					lst->fd_i = open(lst->redir[i].file, FLAG_INFILE_STD);
				else if (lst->redir[i].type == in_double)
					lst->fd_i = open(lst->redir[i].file, FLAG_INFILE_STD); //HERE_DOC
				else if (lst->redir[i].type == out_simple)
					lst->fd_o = open(lst->redir[i].file, FLAG_OUTFILE_STD, 0000644);
				else if (lst->redir[i].type == out_double)
					lst->fd_o = open (lst->redir[i].file, FLAG_OUTFILE_APPEND, 0000644);
				i++;
			}
		}
		lst = lst->next;
	}
}
