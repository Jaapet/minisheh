/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 19:32:20 by ggualerz          #+#    #+#             */
/*   Updated: 2023/07/10 19:29:20 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

void ft_printf_err(char* bin_name, char* args, char* err_msg) 
{
    int 	original_stderr;
	char	*tmp;
	char	*tmp2;
	char 	*buff;
	
	tmp = ft_strjoin(BASH_NAME_ERR, bin_name);
	tmp2 = ft_strjoin(tmp, ": ");
	free(tmp);
	tmp = ft_strjoin(tmp2, args);
	free(tmp2);
	tmp2 = ft_strjoin(tmp, ": ");
	free (tmp);
	tmp = ft_strjoin(tmp2, err_msg);
	buff = ft_strjoin(tmp,"\n");
	free(tmp);
	free(tmp2);
	original_stderr = dup(STDERR_FILENO);
    dup2(STDOUT_FILENO, STDERR_FILENO);
	printf("%s",buff);
	free(buff);
    dup2(original_stderr, STDERR_FILENO);
}

char *ft_str_tolower(char *str)
{
	char *out_str;
	size_t str_len;
	size_t i;

	str_len = ft_strlen(str);
	out_str = ft_calloc(str_len + 1, sizeof(char));
	if (out_str == NULL)
		return (NULL);
	i = 0;
	while (i < str_len)
	{
		out_str[i] = ft_tolower(str[i]);
		i++;
	}
	return (out_str);
}