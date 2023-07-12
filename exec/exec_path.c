/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 15:39:19 by ggualerz          #+#    #+#             */
/*   Updated: 2023/07/12 23:57:54 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static char	*ft_isolate_path(char **envp)
{
	size_t	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp("PATH", envp[i], 4) == 0)
			return (envp[i]);
		i++;
	}
	return (NULL);
}

char	**ft_parse_path(t_ms *ms)
{
	char	*temp_str;
	char	**path;

	temp_str = ft_isolate_path(ms->envp);
	temp_str = ft_strtrim(temp_str, "PATH=");
	path = ft_split(temp_str, ':');
	free_ptr(temp_str);
	return (path);
}
