/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sexy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 22:11:24 by ggualerz          #+#    #+#             */
/*   Updated: 2023/07/12 23:57:54 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sexy.h"

void	ft_banner(void)
{
	printf("%s\n  __  __ _       _  _____ _          _\n |  \\/  (_)   ", PUR);
	printf("  (_)/ ____| |        | |\n | \\  / |_ _ __  _| (___ | |__");
	printf("   ___| |__\n | |\\/| | | '_ \\| |\\___ \\| '_ \\ / _ \\ '_ \\");
	printf("\n | |  | | | | | | |____) | | | |  __/ | | |\n |_|  |_|_|_| |_|_");
	printf("|_____/|_| |_|\\___|_| |_|\n");
	printf("%s\t     ndesprez X ggualerz\n%s\n\n", CYA, STD);
}

static char	*ft_isolate_env_var(char **env, char *var)
{
	size_t	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(var, env[i], ft_strlen(var)) == 0)
			return (env[i]);
		i++;
	}
	return (NULL);
}

char	*ft_prompt_str(char **env)
{
	char	*username;
	char	*trimed;
	char	*out;

	username = ft_isolate_env_var(env, "LOGNAME=");
	if (username == NULL)
		return (ft_strdup("minisheh> "));
	trimed = ft_strtrim(username, "LOGNAME=");
	if (trimed == NULL)
		return (ft_strdup("minisheh> "));
	out = ft_strjoin(trimed, "@minisheh> ");
	free_ptr(trimed);
	if (out == NULL)
		return (ft_strdup("minisheh> "));
	return (out);
}
