/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 15:39:19 by ggualerz          #+#    #+#             */
/*   Updated: 2023/07/09 16:07:57 by ggualerz         ###   ########.fr       */
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
	// if (temp_str == NULL)
		// ft_exit(ERR_PARSE_PATH, pipex);
	temp_str = ft_strtrim(temp_str, "PATH=");
	// if (temp_str == NULL)
		// ft_exit(ERR_MALLOC, pipex);
	path = ft_split(temp_str, ':');
	// if (path == NULL)
		// ft_exit(ERR_MALLOC, pipex);
	free(temp_str);
	return (path);
}