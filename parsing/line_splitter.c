/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_splitter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 18:00:11 by ndesprez          #+#    #+#             */
/*   Updated: 2023/06/19 18:08:51 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	update_quote(char quote, char cur)
{
	if (!quote && (cur == '\'' || cur == '"'))
		return (cur);
	else if (quote && cur == quote)
		return (0);
	return (quote);
}

static int	count_cmds(char *line)
{
	int		i;
	int		count;
	char	quote;

	i = 0;
	count = 0;
	quote = 0;
	while (line[i])
	{
		quote = update_quote(quote, line[i]);
		if (line[i] == '|' && !quote && line[i])
			count++;
		i++;
	}
	return (count + 1);
}

static char	*cut_cmd(char *line)
{
	int		i;
	char	*cmd;
	char	quote;

	i = 0;
	quote = 0;
	while ((line[i] != '|' || quote) && line[i])
	{
		quote = update_quote(quote, line[i]);
		i++;
	}
	cmd = malloc(sizeof(char) * (i + 1));
	if (cmd == NULL)
		return (NULL);
	i = 0;
	while ((line[i] != '|' || quote) && line[i])
	{
		quote = update_quote(quote, line[i]);
		cmd[i] = line[i];
		i++;
	}
	cmd[i] = '\0';
	return (cmd);
}

char	**split_line(char *line)
{
	char	**list;
	int		i;
	char	quote;

	i = 0;
	quote = 0;
	list = ft_calloc((count_cmds(line) + 1), sizeof(char *));
	if (list == NULL)
		return (NULL);
	while (*line)
	{
		list[i] = cut_cmd(line);
		i++;
		while ((*line != '|' || quote) && *line)
		{
			quote = update_quote(quote, *line);
			line++;
		}
		if (*line == '|' && !quote && *line)
			line++;
	}
	if (*(line - 1) == '|' && !quote)
		list[i] = cut_cmd(line - 1);
	return (list);
}

// int main(int argc, char **argv)
// {
// 	printf("%d\n", count(argv[1]));
// 	char **list = split_line(argv[1]);
// 	printf("%s\n%s\n%s\n%s\n%s\n%s\n", list[0], list[1], list[2], list[3], list[4], list[5]);
// 	printf("c : %c\n", *(argv[1]+1));
// }