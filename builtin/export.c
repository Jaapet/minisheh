/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 16:37:03 by ggualerz          #+#    #+#             */
/*   Updated: 2023/07/12 23:18:12 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static void	ft_rm_env_2(t_ms *ms, char *unset_arg)
{
	char	**new_env;
	char	*temp;
	size_t	i;
	size_t	j;

	if (unset_arg == NULL || ft_strlen(unset_arg) == 0
		|| ft_var_in_env(ms->envp, unset_arg) == FALSE)
		return ;
	new_env = ft_calloc(ft_get_env_size(ms->envp) + 1, sizeof(char **));
	temp = ft_strdup(unset_arg);
	i = 0;
	j = 0;
	while (ms->envp[i] != NULL)
	{
		if (ft_strncmp(ms->envp[i], temp, ft_strlen(temp)) != 0)
		{
			new_env[j] = ft_strdup(ms->envp[i]);
			j++;
		}
		i++;
	}
	free(temp);
	ft_free_env(ms);
	ms->envp = new_env;
}

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

static void	ft_group_export(t_ms *ms, char **cmd, int i)
{
	char	*temp;

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
		ft_rm_env_2(ms, temp);
		free(temp);
		ft_add_env(ms, cmd[i]);
	}
}

int	ft_export(t_ms *ms, char **cmd)
{
	size_t	i;

	if (cmd == NULL || cmd[1] == NULL)
		ft_export_list(ms->envp);
	else
	{
		i = 1;
		while (cmd[i])
		{
			ft_group_export(ms, cmd, i);
			i++;
		}
	}
	return (0);
}
