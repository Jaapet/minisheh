/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:33:44 by ggualerz          #+#    #+#             */
/*   Updated: 2023/06/11 22:01:40 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void	ft_init_exec(t_ms *ms)
{
	ft_init_pipes(ms);
	ms->node_nb = ft_lst_size(ms->node_lst);
	ft_lst_set_index(ms->node_lst);
	ft_assign_fd(ms);
	ft_set_redir(ms);

}

void	ft_exec(t_ms *ms, char **envp)
{
	t_node	*cur_node;
	
	ft_init_exec(ms);
	cur_node = ms->node_lst;
	while (cur_node)
	{
		ft_fork(ms, envp, cur_node->index);
		cur_node = cur_node->next;
	}
	ft_close_pipes(ms);
	cur_node = ms->node_lst;
	while (cur_node)
	{
		waitpid(cur_node->pid, NULL, 0);
		cur_node = cur_node->next;
	}
}
