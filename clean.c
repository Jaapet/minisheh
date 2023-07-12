/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 15:43:48 by ggualerz          #+#    #+#             */
/*   Updated: 2023/07/12 23:57:54 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_clean_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free_ptr(tab[i]);
		i++;
	}
	free_ptr(tab);
}

void	ft_triple_free(char *ptr, char *ptr2, char *ptr3)
{
	free_ptr(ptr);
	free_ptr(ptr2);
	free_ptr(ptr3);
}
