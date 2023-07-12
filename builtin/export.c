/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 16:37:03 by ggualerz          #+#    #+#             */
/*   Updated: 2023/07/12 19:44:16 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static void	ft_export_list(char **envp)
{
	size_t	i;
	char	*temp_str;
	char	*ptr;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp("_=", envp[i], 2) != 0)
		{
			temp_str = ft_calloc(ft_strlen(envp[i]) + 3, sizeof(char *));
			ft_strlcpy(temp_str, envp[i], ft_strlen(envp[i]) + 1);
			ptr = ft_strchr(temp_str, '=');
			if (ptr != NULL)
			{
				ft_memmove(ptr + 1, ptr, ft_strlen(ptr));
				*(ptr + 1) = '"';
				*(ptr + ft_strlen(ptr)) = '"';
			}
			printf("declare -x %s\n", temp_str);
			free(temp_str);
		}
		i++;
	}
}

int	ft_export(t_ms *ms, char **cmd)
{
	size_t	i;
	char	*temp;

	if (cmd == NULL || cmd[1] == NULL)
		ft_export_list(ms->envp);
	else
	{
		i = 1;
		while (cmd[i])
		{
			if (ft_var_syntax("export", cmd[i]) == FALSE)
			{
				temp = NULL;
				g_ms->last_errcode = 1;
			}
			else if (ft_var_in_env(ms->envp, cmd[i]) == FALSE)
				ft_add_env(ms, cmd[i]);
			else if (ft_var_in_env(ms->envp, cmd[i]) == TRUE
				&& ft_strchr(cmd[i], '=') != NULL)
			{
				temp = ft_isolate_var(cmd[i]);
				ft_rm_env(ms, temp);
				free(temp);
				ft_add_env(ms, cmd[i]);
			}
			i++;
		}
	}
	return (0);
}
