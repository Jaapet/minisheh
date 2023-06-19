/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:04:41 by ndesprez          #+#    #+#             */
/*   Updated: 2023/06/19 21:14:57 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	update_mult(char mult, char c)
{
	if (!mult)
		return (c);
	else
		return (0);
}

static int	count_redir(char *cmd)
{
	int		i;
	int		count;
	char	mult;
	char	quote;

	i = 0;
	count = 0;
	quote = 0;
	mult = 0;
	while (cmd[i])
	{
		quote = update_quote(quote, cmd[i]);
		if ((cmd[i] == '<' || cmd[i] == '>') && !quote && cmd[i])
		{
			if (cmd[i] != mult)
				count++;
			mult = update_mult(mult, cmd[i]);
		}
		else
			mult = 0;
		i++;
	}
	return (count);
}

static int	set_redir(t_node **node, int j, char *cmd, int i)
{
	if (cmd[i] == '<' && cmd[i + 1] == '<')
	{
		(*node)->redir[j].type = in_double;
		i += 2;
	}
	else if (cmd[i] == '<')
	{
		(*node)->redir[j].type = in_simple;
		i += 1;
	}
	else if (cmd[i] == '>' && cmd[i + 1] == '>')
	{
		(*node)->redir[j].type = out_double;
		i += 2;
	}
	else if (cmd[i] == '>')
	{
		(*node)->redir[j].type = out_simple;
		i += 1;
	}
	return (i);
}

static int	add_redir(t_node **node, int j, char *cmd, int i)
{
	char	quote;

	i = set_redir(node, j, cmd, i);
	while (cmd[i] == ' ')
		i++;
	quote = 0;
	while ((cmd[i] != ' ' || quote) && cmd[i])
	{
		quote = update_quote(quote, cmd[i]);
		if (cmd[i] != '\'' && cmd[i] != '"')
			//catchar
		i++;
	}
	return (i);
}

void	proc_redir(t_node **node, char *cmd)
{
	int		i;
	int		j;
	char	quote;
	char	*cpy;

	(*node)->redir = ft_calloc(count_redir(cpy) + 1, sizeof(t_redir));
	if (!(*node)->redir)
		return (NULL);
	cpy = ft_strtrim(cmd, " ");
	i = 0;
	j = 0;
	quote = 0;
	while (cpy[i])
	{
		quote = update_quote(quote, cpy[i]);
		if ((cpy[i] == '<' || cpy[i] == '>') && !quote && cpy[i])
		{
			i = add_redir(node, j, cpy, i);
			j++;
		}
		else
			i++;
	}
	//proc cmd
}

// int main(int argc, char **argv)
// {
// 	printf("%d\n", count_redir(argv[1]));
// 	// char **list = split_line(argv[1]);
// 	// printf("%s\n%s\n%s\n%s\n%s\n%s\n", list[0], list[1], list[2], list[3], list[4], list[5]);
// 	// printf("c : %c\n", *(argv[1]+1));
// }