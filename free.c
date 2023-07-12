/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 20:55:34 by ndesprez          #+#    #+#             */
/*   Updated: 2023/07/13 00:03:58 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_lex(void)
{
	t_lex	*temp;

	temp = g_ms->lex_first;
	while (temp && temp->next)
	{
		free_ptr(temp->word);
		temp = temp->next;
	}
	if (temp)
	{
		free_ptr(temp->word);
		free_ptr(temp);
	}
}

static void	free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free_ptr(tab[i]);
		i++;
	}
}

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
		free_ptr(temp);
	}
}

void	free_ptr(void *ptr)
{
	if (ptr != NULL)
		free(ptr);
	ptr = NULL;
}
