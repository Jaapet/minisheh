/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:36:47 by ggualerz          #+#    #+#             */
/*   Updated: 2023/07/12 23:47:18 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void static	ft_free_rl(char *rl)
{
	free_lex();
	free_exe();
	free(rl);
}

void	ft_init(char **env, int *ac, char **av)
{
	ac = 0;
	av = NULL;
	g_ms = ft_calloc(1, sizeof(t_ms));
	g_ms->envp = ft_dup_env(env);
	ft_banner();
	g_ms->prompt = ft_prompt_str(g_ms->envp);
	handle();
}

void	ft_rl_exit(char *rl)
{
	if (!rl)
	{
		printf("exit\n");
		exit(0);
	}
}

int	main(int ac, char **av, char **env)
{
	char	*rl;

	ft_init(env, &ac, av);
	while (1)
	{
		rl = readline(g_ms->prompt);
		ft_rl_exit(rl);
		if (rl[0] == '\0')
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
		ft_free_rl(rl);
	}
	return (0);
}
