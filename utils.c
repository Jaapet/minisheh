/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 19:32:20 by ggualerz          #+#    #+#             */
/*   Updated: 2023/06/25 19:48:36 by ggualerz         ###   ########.fr       */
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
