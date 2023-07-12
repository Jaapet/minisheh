/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:48:00 by ndesprez          #+#    #+#             */
/*   Updated: 2023/07/12 23:10:25 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

bool	ft_var_in_env(char **env, char *var)
{
	size_t	i;
	char	*varname;

	i = 0;
	if (ft_strchr(var, '=') != NULL)
		varname = ft_isolate_var(var);
	else
		varname = ft_strdup(var);
	while (env[i])
	{
		if (ft_strncmp(env[i], varname, ft_strlen(varname)) == 0
			&&env[i][ft_strlen(varname)] == '=')
			return (free(varname), TRUE);
		else if (ft_strncmp(env[i], varname, ft_strlen(varname)) == 0
			&& env[i][ft_strlen(varname)] == '\0')
			return (free(varname), TRUE);
		i++;
	}
	return (free(varname), FALSE);
}

char	*ft_get_env_value(char **env, char *var)
{
	size_t	i;
	char	*varname;

	i = 0;
	if (ft_strchr(var, '=') != NULL)
		varname = ft_isolate_var(var);
	else
		varname = ft_strdup(var);
	while (env[i])
	{
		if (ft_strncmp(env[i], varname, ft_strlen(varname)) == 0
			&& env[i][ft_strlen(varname)] == '=')
			return (free(varname), env[i]);
		else if (ft_strncmp(env[i], varname, ft_strlen(varname)) == 0
			&& env[i][ft_strlen(varname)] == '\0')
			return (free(varname), env[i]);
		i++;
	}
	return (free(varname), NULL);
}

void	ft_rm_env(t_ms *ms, char *unset_arg)
{
	char	**new_env;
	char	*temp;
	size_t	i;
	size_t	j;

	if (unset_arg == NULL || ft_strlen(unset_arg) == 0
		|| ft_var_in_env(ms->envp, unset_arg) == FALSE)
		return ;
	new_env = ft_calloc(ft_get_env_size(ms->envp) + 1, sizeof(char **));
	temp = ft_strjoin(unset_arg, "=");
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

char	*ft_isolate_var(char *full_var)
{
	char	*out;
	char	*to_rm;

	out = ft_strdup(full_var);
	to_rm = ft_strchr(out, ' ');
	if (to_rm != NULL)
		*to_rm = '\0';
	to_rm = ft_strchr(out, '=');
	if (to_rm != NULL)
		*to_rm = '\0';
	return (out);
}

char	*ft_isolate_val(char *full_var)
{
	return (ft_strdup(ft_strchr(full_var, '=') + 1));
}
