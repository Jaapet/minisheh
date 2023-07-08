/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:14:53 by ndesprez          #+#    #+#             */
/*   Updated: 2023/07/08 15:49:01 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	*rem_quotes(char *word, int count)
{
	char	*new;
	int		i;
	int		j;
	char	quote;

	i = 0;
	j = 0;
	quote = 0;
	new = ft_calloc(ft_strlen(word) + 1 - (count * 2), sizeof(char));
	if (!new)
		return (NULL);
	while (word[i])
	{
		if (((word[i] == '\'' || word[i] == '"') && !quote)
			|| (word[i] == quote && quote))
			quote = update_quote(quote, word[i]);
		else
		{
			new[j] = word[i];
			j++;
		}
		i++;
	}
	return (new);
}

char	*proc_quote(char *word)
{
	char	quote;
	int		i;
	int		count;
	char	*new;

	i = 0;
	quote = 0;
	count = 0;
	while (word[i])
	{
		if ((word[i] == '\'' || word[i] == '"') && !quote)
			count++;
		quote = update_quote(quote, word[i]);
		i++;
	}
	new = rem_quotes(word, count);
	return (new);
}

// int	main(void)
// {
// 	printf("%s\n", proc_quote("ab\"'c'\"de' f'g"));
// }
