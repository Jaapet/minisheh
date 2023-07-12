/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 20:55:34 by ndesprez          #+#    #+#             */
/*   Updated: 2023/07/12 23:47:05 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_lex(void)
{
	t_lex	*temp;

	temp = g_ms->lex_first;
	while (temp && temp->next)
	{
		free(temp->word);
		temp = temp->next;
	}
	if (temp)
	{
		free(temp->word);
		free(temp);
	}
}

static void	free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
}

// static void	free_redir(t_redir *tab)
// {
// 	size_t	i;

// 	i = 0;
// 	if (tab->arg == NULL)
// 	{
// 		free(tab);
// 		return ;
// 	}
// 	while (tab + i)
// 	{
// 		// free((tab + i)->arg);
// 		free(tab + i);
// 		i++;
// 	}
// 	free(tab);
// }

void	free_exe(void)
{
	t_exe	*temp;

	temp = g_ms->exe_first;
	while (temp && temp->next)
	{
		free_tab(temp->cmd);
		temp = temp->next;
	}
	if (temp)
	{
		free_tab(temp->cmd);
		free(temp);
	}
}
