/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:36:47 by ggualerz          #+#    #+#             */
/*   Updated: 2023/06/25 20:17:44 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <readline/readline.h>
#include <readline/history.h>

static t_ms *dummy_ms(void)
{
	t_ms	*dummy;
	t_node	*node1;
	// t_node	*node2;
	// t_node	*node3;

	dummy = ft_calloc(1, sizeof(t_ms));
	
	node1 = ft_calloc(1, sizeof(t_node));
	// node2 = ft_calloc(1, sizeof(t_node));
	// node3 = ft_calloc(1, sizeof(t_node));

	// node1->cmd = ft_calloc(3, sizeof(char *));
	// node1->cmd[0] = ft_strdup("/bin/cat");
	// node1->is_redir = TRUE;
	// node1->redir_t = RD_I_S;
	// node1->i_file = ft_strdup("dummy.txt");

	// node2->cmd = ft_calloc(2, sizeof(char *));
	// node2->cmd[0] = ft_strdup("/usr/bin/rev");
	// node2->is_redir = FALSE;

	// node3->cmd = ft_calloc(2, sizeof(char *));
	// node3->cmd[0] = ft_strdup("/usr/bin/wc");
	// node3->is_redir = FALSE;

	dummy->node_nb = 1;
	dummy->node_lst = node1;
	node1->next = NULL;
	// node2->next = NULL;
	// node3->next = NULL;
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
	char **cmd;
	cmd = ft_calloc(5, sizeof(char *));
	cmd[0] = ft_strdup("export");
	cmd[1] = ft_strdup("2A=42");
	cmd[2] = ft_strdup("B_C=42");
	cmd[3] = ft_strdup("C=42");
	char **cmd2;
	cmd2 = ft_calloc(5, sizeof(char *));
	cmd2[0] = ft_strdup("unset");
	cmd2[1] = ft_strdup("2A");
	cmd2[2] = ft_strdup("C");
	// ft_echo(cmd);
	// ft_env(ms);
	rl = NULL;
	while (1)
	{
		ms->prompt = ft_prompt_str(env);
		rl = readline(ms->prompt);
		add_history(rl);
		// ms->node_lst = parse(rl)s;
		// ft_exec(ms, env);
		// ft_pwd();
		if (*rl == 'p')
			ft_pwd();
		else if (*rl == 'e')
			ft_env(ms);
		else if (*rl == 'X')
			ft_export(ms, cmd);
		else if (*rl == 'x')
			ft_export(ms, NULL);
		else if (*rl == 'u')
			ft_unset(ms, cmd2);
		else // cd
		{
			ft_cd(rl);
		}
	}
	//ft_exec(ms, env);
	return (0);
}