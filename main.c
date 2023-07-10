/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:36:47 by ggualerz          #+#    #+#             */
/*   Updated: 2023/07/10 19:30:18 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <readline/readline.h>
#include <readline/history.h>

static t_ms *dummy_ms(void)
{
	t_ms	*dummy;

	dummy = ft_calloc(1, sizeof(t_ms));

	return (dummy);
}

int main(int ac, char **av, char **env)
{
	t_ms *ms;
	char *rl;
	
	ms = dummy_ms();
	ac = 0;
	av = NULL;
	ms->envp = ft_dup_env(env);
	ft_banner();
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
	ms->prompt = ft_prompt_str(ms->envp);
	while (1)
	{
		rl = readline(ms->prompt);
		add_history(rl);
		// rl = "ls | echo toto | rev";
		ms->lex_first = parse(rl, ms->envp);
		ft_exec(ms, ms->envp);
	}
	// ft_exec(ms, env);
	ft_clean_tab(ms->envp);
	return (0);
}