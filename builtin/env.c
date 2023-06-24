/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 20:07:03 by ggualerz          #+#    #+#             */
/*   Updated: 2023/06/24 17:57:53 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	ft_env(t_ms *ms) // probleme $_ non mis a jour
{
	size_t i;

	i = 0;
	while (ms->envp[i])
	{
		if (ft_strchr(ms->envp[i], '=') != NULL)
			printf("%s\n",ms->envp[i]);
		i++;
	}
}
