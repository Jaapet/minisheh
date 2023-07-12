/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:40:23 by ggualerz          #+#    #+#             */
/*   Updated: 2023/07/12 23:57:54 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

size_t	ft_get_env_size(char **envp)
{
	size_t	i;

	i = 0;
	while (envp[i] != NULL)
		i++;
	return (i);
}

void	ft_free_env(t_ms *ms)
{
	size_t	i;

	i = 0;
	while (ms->envp[i])
	{
		free_ptr(ms->envp[i]);
		i++;
	}
	free_ptr(ms->envp);
}

char	**ft_dup_env(char **envp)
{
	char	**new_env;
	size_t	i;

	new_env = ft_calloc(ft_get_env_size(envp) + 1, sizeof(char **));
	i = 0;
	while (envp[i] != NULL)
	{
		new_env[i] = ft_strdup(envp[i]);
		i++;
	}
	return (new_env);
}

void	ft_add_env(t_ms *ms, char *export_arg)
{
	char	**new_env;
	size_t	i;

	if (export_arg == NULL || ft_strlen(export_arg) == 0)
		return ;
	new_env = ft_calloc(ft_get_env_size(ms->envp) + 2, sizeof(char **));
	i = 0;
	while (ms->envp[i] != NULL)
	{
		new_env[i] = ft_strdup(ms->envp[i]);
		i++;
	}
	new_env[i] = ft_strdup(export_arg);
	ft_free_env(ms);
	ms->envp = new_env;
}

bool	ft_var_syntax(char *bin_name, char *var)
{
	size_t	i;
	char	*varname;

	i = 0;
	if (ft_strchr(var, '=') != NULL)
		varname = ft_isolate_var(var);
	else
		varname = ft_strdup(var);
	if (ft_isalpha(varname[0]) == 0 && varname[0] != '_')
	{
		ft_printf_err(bin_name, var, "not a valid identifier");
		return (free_ptr(varname), FALSE);
	}
	i = 1;
	while (varname[i])
	{
		if (varname[i] != '_' && ft_isalnum(varname[i]) != 1)
		{
			ft_printf_err(bin_name, var, "not a valid identifier");
			return (free_ptr(varname), FALSE);
		}
		i++;
	}
	return (free_ptr(varname), TRUE);
}
