/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:41:55 by ndesprez          #+#    #+#             */
/*   Updated: 2023/07/10 20:51:51 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	control_bs(int var)
{
	var = 1;
	if (g_ms->in_exec)
		ft_putstr_fd("\n", STDERR_FILENO);
	errno = var;
	if (signal(SIGINT, control_c) == SIG_ERR)
		perror("signal");
}

void	control_c(int var)
{
	var = 1;
	if (g_ms->in_exec)
		ft_putstr_fd("\n", STDERR_FILENO);
	else if (g_ms->in_heredoc)
	{
		if (g_ms->heredoc_pid)
		{
			printf("\n");
			kill(g_ms->heredoc_pid, SIGTERM);
			g_ms->in_heredoc = FALSE;
		}
	}
	else
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	g_ms->last_errcode = 1;
	errno = 0;
	if (signal(SIGQUIT, SIG_IGN) == SIG_ERR)
		perror("signal");
}

void	handle(void)
{
	errno = 0;
	if (signal(SIGINT, control_c) == SIG_ERR)
		perror("signal");
	errno = 0;
	if (signal(SIGQUIT, SIG_IGN) == SIG_ERR)
		perror("signal");
}
