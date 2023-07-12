/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 20:07:03 by ggualerz          #+#    #+#             */
/*   Updated: 2023/07/12 19:41:34 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	ft_env(t_ms *ms)
{
	size_t	i;

	i = 0;
	while (ms->envp[i])
	{
		if (ft_strchr(ms->envp[i], '=') != NULL)
			printf("%s\n", ms->envp[i]);
		i++;
	}
	return (0);
}
