/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:33:44 by ggualerz          #+#    #+#             */
/*   Updated: 2023/06/11 17:11:09 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void	ft_init_exec(t_ms *ms)
{
	ft_init_pipes(ms);
	ms->node_nb = ft_lst_size(ms->node_lst);
	ft_lst_set_index(ms->node_lst);
	ft_assign_fd(ms);
	ft_set_redir(ms);

}

void	ft_exec(t_ms *ms)
{
	void	ft_init_exec(t_ms *ms);
}
