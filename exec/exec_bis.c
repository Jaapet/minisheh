/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 20:46:47 by ggualerz          #+#    #+#             */
/*   Updated: 2023/07/12 21:06:28 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void	ft_lex_to_exe_cmdnb(t_ms *ms)
{
	t_lex	*curr_node;
	size_t	cmd_i;

	curr_node = ms->lex_first;
	cmd_i = 0;
	while (curr_node)
	{
		if (curr_node->type == is_command)
			cmd_i++;
		curr_node = curr_node->next;
	}
	ms->cmd_nb = cmd_i;
}

static void	ft_group_below(t_lex *curr_lex, t_exe *curr_exe, t_lex *last_pipe)
{
	size_t	i;

	while (curr_lex)
	{
		if (curr_lex->type == is_command)
		{
			curr_exe->cmd = ft_calloc(ft_cargs(curr_lex) + 2, sizeof(char *));
			curr_exe->cmd[0] = ft_strdup(curr_lex->word);
			ft_lex_to_exe_redir(curr_exe, last_pipe);
			i = 1;
		}
		else if (curr_lex->type == is_arg)
		{
			curr_exe->cmd[i] = ft_strdup(curr_lex->word);
			i++;
		}
		else if (curr_lex->type == is_pipe)
		{
			last_pipe = curr_lex->next;
			curr_exe->next = ft_calloc(1, sizeof(t_exe));
			curr_exe = curr_exe->next;
		}
		curr_lex = curr_lex->next;
	}
}

static t_exe	*ft_lex_to_exe_cmd_build(t_ms *ms)
{
	t_lex	*curr_lex;
	t_exe	*curr_exe;
	t_exe	*first_exe;
	t_lex	*last_pipe;

	first_exe = ft_calloc(1, sizeof(t_exe));
	curr_lex = ms->lex_first;
	curr_exe = first_exe;
	last_pipe = ms->lex_first;
	ft_group_below(curr_lex, curr_exe, last_pipe);
	return (first_exe);
}

void	ft_lex_to_exe_redir(t_exe *curr_exe, t_lex *curr_lex)
{
	size_t	redir_nb;
	size_t	i;

	if (curr_lex->type == is_pipe)
		curr_lex = curr_lex->next;
	redir_nb = ft_lex_to_exe_redir_count(curr_lex);
	curr_exe->redir = ft_calloc(redir_nb + 1, sizeof(t_redir));
	i = 0;
	while (curr_lex)
	{
		if (curr_lex->type >= si_redir && curr_lex->type <= do_redir)
		{
			(curr_exe->redir)[i].index = i;
			(curr_exe->redir)[i].type = curr_lex->type;
		}
		if (curr_lex->type == is_file)
		{
			(curr_exe->redir)[i].arg = curr_lex->word;
			i++;
		}
		if (curr_lex->type == is_pipe)
			break ;
		curr_lex = curr_lex->next;
	}
}

void	ft_init_exec(t_ms *ms)
{
	ft_lex_to_exe_cmdnb(ms);
	ms->exe_first = ft_lex_to_exe_cmd_build(ms);
	ft_acess_cmd(ms);
	ft_init_pipes(ms);
	ft_lst_set_index(ms->exe_first);
	ft_assign_fd(ms);
	ft_set_redir(ms);
}
