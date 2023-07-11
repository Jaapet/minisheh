/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:36:47 by ggualerz          #+#    #+#             */
/*   Updated: 2023/07/11 21:59:30 by ggualerz         ###   ########.fr       */
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

	if (env[0] == NULL)
		return(ft_putstr_fd("[1]\t1337 not a segmentation fault\t./minishell\n\tan env is mandatory\n", 2), 1);
	g_ms = dummy_ms();
	ac = 0;
	av = NULL;
	g_ms->envp = ft_dup_env(env);
	ft_banner();
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
		// if (rl[0] == '^') /////////DEBUG
		// 	break;
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
	// system("leaks minishell");
	ft_clean_tab(g_ms->envp);
	return (0);
}