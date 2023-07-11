/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:33:44 by ggualerz          #+#    #+#             */
/*   Updated: 2023/07/11 21:11:20 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
static void	ft_lex_to_exe_cmdnb (t_ms *ms)
{
	t_lex *curr_node;
	size_t cmd_i;

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

static size_t ft_lex_to_exe_redir_count(t_lex *last_pipe)
{
	t_lex *curr_node;
	size_t redir_i;

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

static void ft_lex_to_exe_redir(t_exe *curr_exe, t_lex *curr_lex)
{
	size_t redir_nb;
	size_t i;
	// t_lex *curr_lex;
	
	if (curr_lex->type == is_pipe)
		curr_lex = curr_lex->next;
	redir_nb = ft_lex_to_exe_redir_count(curr_lex);
	curr_exe->redir = ft_calloc(redir_nb + 1, sizeof(t_redir));
	i = 0;
	while (curr_lex)
	{
		if (curr_lex->type  >= si_redir && curr_lex->type <= do_redir )
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
static size_t ft_cargs(t_lex *begin)
{
	t_lex *curr_lex;
	size_t args_nb;

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
static t_exe *ft_lex_to_exe_cmd_build(t_ms *ms)
{
	t_lex *curr_lex;
	t_exe *curr_exe;
	t_exe *first_exe;
	t_lex *last_pipe;
	size_t i;

	first_exe = ft_calloc(1, sizeof(t_exe));
	curr_lex = ms->lex_first;
	curr_exe = first_exe;
	last_pipe = ms->lex_first;
	while(curr_lex)
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
	return (first_exe);
}

static void ft_lex_to_exe(t_ms *ms)
{
	
	//
	ft_lex_to_exe_cmdnb(ms);
	// ms->exe_first = ft_calloc(1, sizeof(t_exe));
	ms->exe_first = ft_lex_to_exe_cmd_build(ms);
	ft_acess_cmd(ms);
	// Changer le cmd[0] en full path et check l'access
	
}
static void	ft_init_exec(t_ms *ms)
{
	ft_lex_to_exe(ms);
	ft_init_pipes(ms);
	ft_lst_set_index(ms->exe_first);
	ft_assign_fd(ms);
	ft_set_redir(ms);

}
// int		ft_error_decode(int *status)
// {
// 	if (WIFEXITED(status)) 
// 	{
//     int exit_status = WEXITSTATUS(status);
//     // Traitement lorsque le processus s'est terminé normalement
// 	} 
// 	else if (WIFSIGNALED(status)) 
// 	{
//     int signal_number = WTERMSIG(status);
//     // Traitement lorsque le processus s'est terminé à cause d'un signal
// 	} 
// 	// else if (WIFSTOPPED(status)) 
// 	// {
//     // int signal_number = WSTOPSIG(status);
//     // // Traitement lorsque le processus s'est arrêté en raison d'un signal
// 	// } 
// 	// else if (WIFCONTINUED(status)) 
// 	// {
//     // // Traitement lorsque le processus a été repris
// 	// }
// }

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
		if (ft_get_node(ms->exe_first, ms->cmd_nb - 1)->pid == waitpid(cur_node->pid, &ret, 0))
			g_ms->last_errcode = WEXITSTATUS(ret);
		cur_node = cur_node->next;
	}
}
