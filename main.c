/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:36:47 by ggualerz          #+#    #+#             */
/*   Updated: 2023/07/09 20:37:57 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <readline/readline.h>
#include <readline/history.h>

static t_ms *dummy_ms(void)
{
	t_ms	*dummy;
	t_lex	*node1;
	t_lex	*node2;
	t_lex	*node3;
	t_lex	*node4;
	t_lex	*node5;
	t_lex	*node6;
	t_lex	*node7;

	dummy = ft_calloc(1, sizeof(t_ms));
	
	node1 = ft_calloc(1, sizeof(t_lex));
	node2 = ft_calloc(1, sizeof(t_lex));
	node3 = ft_calloc(1, sizeof(t_lex));
	node4 = ft_calloc(1, sizeof(t_lex));
	node5 = ft_calloc(1, sizeof(t_lex));
	node6 = ft_calloc(1, sizeof(t_lex));
	node7 = ft_calloc(1, sizeof(t_lex));

	
	node1->word = ft_strdup("cat");
	node1->type = is_command;
	node1->next = node2;

	node2->word = ft_strdup("<<");
	node2->type = di_redir;
	node2->next = node3;

	node3->word = ft_strdup("EOF");
	node3->type = is_file;
	node3->next = node4;

	node4->word = ft_strdup("<<");
	node4->type = di_redir;
	node4->next = node5;

	node5->word = ft_strdup("EOF");
	node5->type = is_file;
	node5->next = node6;

	node6->word = ft_strdup("|");
	node6->type = is_pipe;
	node6->next = node7;

	node7->word = ft_strdup("rev");
	node7->type = is_command;
	node7->next = NULL;


	dummy->lex_first = node1;
	return (dummy);
}

int main(int ac, char **av, char **env)
{
	t_ms *ms;
	// char *rl;
	
	ms = dummy_ms();
	ac = 0;
	av = NULL;
	ms->envp = ft_dup_env(env);
// ft_banner();
	// char **cmd;
	// cmd = ft_calloc(5, sizeof(char *));
	// cmd[0] = ft_strdup("export");
	// cmd[1] = ft_strdup("2A=42");
	// cmd[2] = ft_strdup("B_C=42");
	// cmd[3] = ft_strdup("C=42");
	// char **cmd2;
	// cmd2 = ft_calloc(5, sizeof(char *));
	// cmd2[0] = ft_strdup("unset");
	// cmd2[1] = ft_strdup("2A");
	// cmd2[2] = ft_strdup("C");
	// // ft_echo(cmd);
	// // ft_env(ms);
	// rl = NULL;
	// ms->prompt = ft_prompt_str(env);
	// while (1)
	// {
	// 	rl = readline(ms->prompt);
	// 	add_history(rl);
	// 	ft_exec(ms, env);
	// }
	ft_exec(ms, env);
	ft_clean_tab(ms->envp);
	return (0);
}