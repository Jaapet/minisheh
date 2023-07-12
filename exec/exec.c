/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:33:44 by ggualerz          #+#    #+#             */
/*   Updated: 2023/07/12 21:06:48 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

size_t	ft_cargs(t_lex *begin)
{
	t_lex	*curr_lex;
	size_t	args_nb;

	args_nb = 0;
	curr_lex = begin;
	while (curr_lex && curr_lex->type != is_pipe)
	{
		if (curr_lex->type == is_arg)
			args_nb++;
		curr_lex = curr_lex->next;
	}
	return (args_nb);
}

size_t	ft_lex_to_exe_redir_count(t_lex *last_pipe)
{
	t_lex	*curr_node;
	size_t	redir_i;

	curr_node = last_pipe;
	redir_i = 0;
	while (curr_node && curr_node->type != is_pipe)
	{
		if (curr_node->type >= si_redir && curr_node->type <= do_redir)
			redir_i++;
		curr_node = curr_node->next;
	}
	return (redir_i);
}

void	ft_exec(t_ms *ms, char **envp)
{
	t_exe	*cur_node;
	int		ret;

	ft_init_exec(ms);
	cur_node = ms->exe_first;
	while (cur_node)
	{
		ft_fork(ms, envp, cur_node->index);
		cur_node = cur_node->next;
	}
	ft_close_pipes(ms);
	cur_node = ms->exe_first;
	while (cur_node)
	{
		if (ms->cmd_nb != 0 
			&& ft_get_node(ms->exe_first, ms->cmd_nb - 1)->pid 
			== waitpid(cur_node->pid, &ret, 0))
			g_ms->last_errcode = WEXITSTATUS(ret);
		cur_node = cur_node->next;
	}
}
