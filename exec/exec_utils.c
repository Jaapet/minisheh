/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:00:52 by ggualerz          #+#    #+#             */
/*   Updated: 2023/06/11 20:08:14 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

t_node	*ft_get_node(t_node *fnode, size_t i)
{
	t_node	*cnode;
	
	cnode = fnode;
	while (cnode != NULL && cnode->index != i)
		cnode = cnode->next;
	return (cnode);
}

void	ft_init_pipes(t_ms *ms)
{
	size_t	i;

	ms->pipes= ft_calloc((ms->node_nb) * 2, sizeof(int));
	if (ms->pipes == NULL)
		{}
		//ft_exit(ERR_DUMMY, ms);
	i = 0;
	while (i < (ms->node_nb) * 2)
	{
		if (pipe(ms->pipes + i) < 0)
		{}
		//	ft_exit(ERR_DUMMY, ms);
		i += 2;
	}
}
void	ft_close_pipes(t_ms *ms)
{
	int	i;

	i = 0;
	while (ms->pipes[i])
	{
		close(ms->pipes[i]);
		i++;
	}
}

void	ft_lst_set_index(t_node *lst)
{
	size_t	i;

	if (lst == NULL)
		return ;
	i = 0;
	while (lst != NULL)
	{
		lst->index = i;
		lst = lst->next;
		i++;
	}
}
size_t	ft_lst_size(t_node *lst)
{
	size_t	i;

	if (lst == NULL)
		return (0);
	i = 1;
	while (lst->next != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
