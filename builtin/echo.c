/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:00:12 by ggualerz          #+#    #+#             */
/*   Updated: 2023/07/09 16:59:30 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
static char *ft_add_str(char *dest, char *to_add)
{
	char *temp;
	
	if (to_add == NULL)
		return (NULL);
	if (dest == NULL)
		dest = ft_strdup(to_add);
	else
	{
		temp = ft_strjoin(dest, " ");
		free(dest);
		dest = temp;
		temp = ft_strjoin(dest, to_add);
		free(dest);
		dest = temp;
	}
	return (dest);
}
static char *ft_add_nl(char *str)
{
	char	*temp;
	temp = ft_strjoin(str, "\n");
	free(str);
	str = temp;
	return (str);
}
static	bool	ft_parse_flag(char *str)
{
	size_t i;
	
	if (str[0] != '-')
		return (FALSE);
	i = 1;
	while (str[i])
	{
		if (str[i] != 'n')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int ft_echo(char **cmd)
{
	size_t	i;
	bool	is_n;
	char	*out;
	
	i = 1;
	is_n = FALSE;
	out = NULL;
	while (cmd[i])
	{
		if (ft_parse_flag(cmd[i]) == FALSE)
			break;
		is_n = TRUE;
		i++;
	}
	while (cmd[i])
	{
		out = ft_add_str(out, cmd[i]);
		i++;
	}
	if (is_n == FALSE)
		out = ft_add_nl(out);
	printf("%s", out);
	if (out != NULL)
		free(out);
	return (0);
}
