/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:36:47 by ggualerz          #+#    #+#             */
/*   Updated: 2023/06/17 16:55:27 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <readline/readline.h>
#include <readline/history.h>

static t_ms *dummy_ms(char **envp)
{
	t_ms	*dummy;
	t_node	*node1;
	t_node	*node2;
	t_node	*node3;

	dummy = ft_calloc(1, sizeof(t_ms));
	dummy->envp = envp;
	
	node1 = ft_calloc(1, sizeof(t_node));
	node2 = ft_calloc(1, sizeof(t_node));
	node3 = ft_calloc(1, sizeof(t_node));

	node1->cmd = ft_calloc(3, sizeof(char *));
	node1->cmd[0] = ft_strdup("/bin/cat");
	node1->is_redir = TRUE;
	node1->redir_t = RD_I_S;
	node1->i_file = ft_strdup("dummy.txt");

	node2->cmd = ft_calloc(2, sizeof(char *));
	node2->cmd[0] = ft_strdup("/usr/bin/rev");
	node2->is_redir = FALSE;

	node3->cmd = ft_calloc(2, sizeof(char *));
	node3->cmd[0] = ft_strdup("/usr/bin/wc");
	node3->is_redir = FALSE;

	dummy->node_nb = 3;
	dummy->node_lst = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;
	return (dummy);
}

int main(int ac, char **av, char **env)
{
	t_ms *ms;
	char *rl;
	
	ms = dummy_ms(env);
	ac = 0;
	av = NULL;
	
	ft_banner();
	while (1)
	{
		ms->prompt = ft_prompt_str(env);
		rl = readline(ms->prompt);
		add_history(rl);
		// ms->node_lst = parse(rl);
		ft_exec(ms, env);
	}
	//ft_exec(ms, env);
	return (0);
}