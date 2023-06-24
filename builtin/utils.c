/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:40:23 by ggualerz          #+#    #+#             */
/*   Updated: 2023/06/24 20:31:37 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

size_t	ft_get_env_size(char **envp)
{
	size_t i;

	i = 0;
	while (envp[i] != NULL)
		i++;
	return (i);
}
void	ft_free_env(t_ms *ms)
{
	size_t i;

	i = 0;
	while (ms->envp[i])
	{
		free(ms->envp[i]);
		i++;
	}
	free(ms->envp);
}
char **ft_dup_env(char **envp)
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
bool	ft_is_in_env(t_ms *ms, char *varname)
{
	size_t i;

	i = 0;
	if (ft_strchr(varname,'=') == NULL) //PB PB PB A REFAIRE
	{
		while (ms->envp[i] != NULL)
		{
			if (ft_strncmp(ms->envp[i], varname, ft_strlen(varname) + 1) == 0)
				return (TRUE);
			i++;
		}
	}
	else
	{
		while (ms->envp[i] != NULL)
		{
			if (ft_strncmp(ms->envp[i], varname, (size_t)(ms->envp[i] - 
			ft_strchr(ms->envp[i], '=')) != 0))
				return (TRUE);
			i++;
		}
	}
	return (FALSE);
}
void	ft_rm_env(t_ms *ms, char *unset_arg)
{
	char	**new_env;
	char	*temp;
	size_t	i;
	size_t	j;
	
	if (unset_arg == NULL || ft_strlen(unset_arg) == 0 || ft_is_in_env(ms, unset_arg) == FALSE)
	{
		printf("toto\n");
		return ;
	}	
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
	to_rm = ft_strchr(out, '=');
	if (to_rm != NULL)
		*to_rm = '\0';
	return (out);
}
// bool	ft_syntax(char *cmd)
// {
// 	L'identifiant doit commencer par une lettre (a-z ou A-Z).
// Les caractères suivants peuvent être des lettres (a-z ou A-Z), des chiffres (0-9) ou le caractère souligné (_).
// Les caractères spéciaux tels que l'espace, les symboles de ponctuation et les caractères de contrôle ne sont pas autorisés.
// }