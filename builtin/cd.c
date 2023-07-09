/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:33:24 by ggualerz          #+#    #+#             */
/*   Updated: 2023/07/09 21:16:10 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	ft_cd(char *path, t_ms *ms)
{
	char	*export_cmd[3];
	char	*temp;
	char	pwd[PATH_MAX];
	
	export_cmd[0] = "export";
	export_cmd[2] = NULL;
	if (chdir(path) != 0)
	{
		perror("cd");
	}
	else
	{
		if(ft_var_in_env(ms->envp, "PWD") == true)
		{
			temp = ft_isolate_val(ft_get_env_value(ms->envp, "PWD"));
			export_cmd[1] = ft_strjoin("OLDPWD=", temp);
			ft_export(ms, export_cmd);
			free(temp);
			free(export_cmd[1]);
		}
		export_cmd[1] = ft_strjoin("PWD=", getcwd(pwd, PATH_MAX));
		ft_export(ms, export_cmd);
		free(export_cmd[1]);
	}
	return (0);
}
