/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:36:47 by ggualerz          #+#    #+#             */
/*   Updated: 2023/06/11 22:29:57 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <readline/readline.h>

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

	dummy->node_nb = 2;
	dummy->node_lst = node1;
	node1->next = node2;
	node2->next = NULL;
	node3->next = NULL;
	return (dummy);
}

int main(int ac, char **av, char **env)
{
	t_ms *ms;
	
	ms = dummy_ms(env);
	// printf("%s\n  __  __ _       _  _____ _          _\n |  \\/  (_)   ", PUR);
	// printf("  (_)/ ____| |        | |\n | \\  / |_ _ __  _| (___ | |__");
	// printf("   ___| |__\n | |\\/| | | '_ \\| |\\___ \\| '_ \\ / _ \\ '_ \\");
	// printf("\n | |  | | | | | | |____) | | | |  __/ | | |\n |_|  |_|_|_| |_|_");
	// printf("|_____/|_| |_|\\___|_| |_|\n");
	// printf("%s\t     ndesprez X ggualerz\n%s", CYA, STD);
	// while (1)
	// {
	// 	printf("\n%s", readline("\033[0;35mMiniSheh>\033[0m"));
	// }
	// check ac;
	ac = 0;
	av = NULL;
	
	ft_exec(ms, env);
	return (0);
}