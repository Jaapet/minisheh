/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 19:32:20 by ggualerz          #+#    #+#             */
/*   Updated: 2023/07/12 23:25:11 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_printf_err(char *bin_name, char *args, char *err_msg)
{
	char	*tmp;
	char	*tmp2;
	char	*buff;

	if (bin_name)
	{
		tmp = ft_strjoin(BASH_NAME_ERR, bin_name);
		tmp2 = ft_strjoin(tmp, ": ");
		free(tmp);
	}
	else
		tmp2 = ft_strjoin(BASH_NAME_ERR, "");
	if (args)
	{
		tmp = ft_strjoin(tmp2, args);
		free(tmp2);
		tmp2 = ft_strjoin(tmp, ": ");
		free (tmp);
	}
	tmp = ft_strjoin(tmp2, err_msg);
	buff = ft_strjoin(tmp, "\n");
	write(2, buff, ft_strlen(buff));
	ft_triple_free(tmp, tmp2, buff);
}

char	*ft_str_tolower(char *str)
{
	char	*out_str;
	size_t	str_len;
	size_t	i;

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

static int	synt_err(void)
{
	g_ms->last_errcode = 258;
	ft_printf_err(NULL, NULL, "Syntax error");
	return (0);
}

static int	check_file(char *file, t_type type)
{
	if (!access(file, F_OK))
	{
		if ((type == so_redir || type == do_redir) && !access(file, W_OK))
			return (1);
		else if (type == si_redir && !access(file, R_OK))
			return (1);
		else
		{
			g_ms->last_errcode = 1;
			ft_printf_err(file, NULL, "Permission denied");
			return (0);
		}
		g_ms->last_errcode = 1;
		ft_printf_err(file, NULL, "Permission denied");
		return (0);
	}
	if (type == si_redir)
	{
		g_ms->last_errcode = 1;
		ft_printf_err(file, NULL, "No such file or directory");
		return (0);
	}
	return (1);
}

int	check_synt(t_lex *list)
{
	int		pipe;
	t_lex	*temp;

	pipe = 1;
	temp = list;
	while (temp)
	{
		if (pipe && temp->type == is_pipe)
			return (synt_err());
		else if (pipe && temp->type == is_command)
			pipe = 0;
		else if (!pipe && temp->type == is_pipe)
			pipe = 1;
		else if (temp->type >= 2 && temp->type <= 5
			&& (!temp->next || temp->next->type != 6))
			return (synt_err());
		else if (temp->type >= 2 && temp->type <= 5 && temp->next->type == 6
			&& !check_file(temp->next->word, temp->type))
			return (0);
		temp = temp->next;
	}
	if (pipe)
		return (synt_err());
	return (1);
}
