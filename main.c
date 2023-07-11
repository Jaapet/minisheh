/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:36:47 by ggualerz          #+#    #+#             */
/*   Updated: 2023/07/11 23:33:33 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_ms *dummy_ms(void)
{
	t_ms	*dummy;

	dummy = ft_calloc(1, sizeof(t_ms));

	return (dummy);
}

int	main(int ac, char **av, char **env)
{
	char	*rl;

	g_ms = dummy_ms();
	ac = 0;
	av = NULL;
	g_ms->envp = ft_dup_env(env);
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
	g_ms->prompt = ft_prompt_str(g_ms->envp);
	handle();
	while (1)
	{
		// rl = ft_strdup("echo toto | rev > a.txt");
		rl = readline(g_ms->prompt);
		if (!rl)
		{
			printf("exit\n");
			exit(0);
		}
		else if (rl[0] == '\0')
			continue ;
		add_history(rl);
		g_ms->lex_first = parse(rl, g_ms->envp);
		if (check_synt(g_ms->lex_first))
		{
			g_ms->in_exec = TRUE;
			if (signal(SIGQUIT, control_bs) == SIG_ERR)
				perror("signal");
			ft_exec(g_ms, g_ms->envp);
			g_ms->in_exec = FALSE;
			if (signal(SIGQUIT, SIG_IGN) == SIG_ERR)
				perror("signal");
		}
	}
	// ft_exec(ms, env);
	ft_clean_tab(g_ms->envp);
	return (0);
}