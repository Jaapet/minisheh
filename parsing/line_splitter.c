/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_splitter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 18:00:11 by ndesprez          #+#    #+#             */
/*   Updated: 2023/07/08 15:45:25 by ndesprez         ###   ########.fr       */
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

static int	iterate(char *quote, char cur)
{
	*quote = update_quote(*quote, cur);
	return (1);
}

static int	count(char *str)
{
	int		i;
	int		count;
	char	quote;

	i = 0;
	count = 0;
	quote = 0;
	while (str[i])
	{
		if ((str[i] != ' ' || quote) && str[i])
		{
			while ((str[i] != ' ' || quote) && str[i])
				i += iterate(&quote, str[i]);
			count++;
		}
		while (str[i] == ' ' && !quote && str[i])
			i += iterate(&quote, str[i]);
	}
	return (count);
}

static char	*cut_word(char *line)
{
	int		i;
	char	quote;
	char	*word;

	i = 0;
	quote = 0;
	while ((line[i] != ' ' || quote) && line[i])
		i += iterate(&quote, line[i]);
	word = ft_calloc(i + 1, sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	quote = 0;
	while ((line[i] != ' ' || quote) && line[i])
	{
		word[i] = line[i];
		i += iterate(&quote, line[i]);
	}
	return (word);
}

char	**split_line(char *str)
{
	char	**list;
	char	quote;
	int		i;

	i = 0;
	quote = 0;
	list = ft_calloc((count(str) + 1), sizeof(char *));
	if (list == NULL)
		return (NULL);
	while (*str)
	{
		if ((*str != ' ' || quote) && *str)
		{
			list[i] = cut_word(str);
			if (!list[i])
				return (NULL);
			i++;
			while ((*str != ' ' || quote) && *str)
				str += iterate(&quote, *str);
		}
		while (*str == ' ' && !quote && *str)
			str += iterate(&quote, *str);
	}
	return (list);
}

// int main(int argc, char **argv)
// {
// 	printf("%d\n", count(argv[1]));
// 	char **list = split_line(argv[1]);
// 	printf("%s\n%s\n%s\n%s\n%s\n%s\n", list[0], list[1], list[2], list[3], list[4], list[5]);
// }
