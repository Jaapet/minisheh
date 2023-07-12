/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 18:51:59 by ggualerz          #+#    #+#             */
/*   Updated: 2023/07/12 19:45:49 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	ft_unset(t_ms *ms, char **cmd)
{
	size_t	i;

	i = 1;
	while (cmd[i])
	{
		if (ft_var_syntax("unset", cmd[i]) == TRUE)
		{
			ft_rm_env(ms, cmd[i]);
		}
		i++;
	}
	return (0);
}
