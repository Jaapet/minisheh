/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_splitter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 18:00:11 by ndesprez          #+#    #+#             */
/*   Updated: 2023/06/11 18:48:57 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	count(char *line)
{
	int		i;
	int		count;
	char	quote;

	i = 0;
	count = 0;
	quote = 0;
	while (line[i])
	{
		if ((line[i] != '|' || quote) && line[i])
		{
			while ((line[i] != '|' || quote) && line[i])
			{
				if (!quote && (line[i] == '\'' || line[i] == '"'))
					quote = line[i];
				else if (quote && line[i] == quote)
					quote = 0;
				i++;
			}
			count++;
		}
		if (line[i] == '|' && !quote && line[i])
			i++;
	}
	return (count);
}

char	**split_line(char *line);

// int main(int argc, char **argv)
// {
// 	printf("%d\n", count(argv[1]));
// }