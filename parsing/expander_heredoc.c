/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_heredoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:36:19 by ndesprez          #+#    #+#             */
/*   Updated: 2023/07/12 21:32:10 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*expand2(char *word, int *i, char **env)
{
	char	*var;
	int		j;

	j = 1;
	while (word[(*i) + j] && is_valid_char(word[(*i) + j]))
		j++;
	if (j > 1)
	{
		var = set_var(word, *i, j, env);
		word = replace_var(word, var, *i, j);
		*i += ft_strlen(var) - 1;
		free(var);
	}
	else
		word = replace_var(word, "", *i, j);
	return (word);
}

char	*expand_heredoc(char *word, char **env)
{
	char	*var;
	int		i;

	i = 0;
	while (word[i])
	{
		if (word[i] == '$' && is_valid_char(word[i + 1]))
		{
			if (word[i + 1] == '?')
			{
				var = ft_itoa(g_ms->last_errcode);
				word = replace_var(word, var, i, 2);
				i += ft_strlen(var) - 1;
				free(var);
			}
			else
				word = expand2(word, &i, env);
		}
		i++;
	}
	return (word);
}

// int main(void)
// {
// 	char	*env[3];
// 	char	*word;

// 	env[0] = "to=42";
// 	env[1] = "titi=";
// 	env[2] = NULL;
// 	word = ft_calloc(6, sizeof(char));
// 	word[0] = 'a';
// 	word[1] = '$';
// 	word[2] = 't';
// 	word[3] = 'o';
// 	word[4] = '\'';
// 	printf("%s\n", expand_heredoc(word, env));
// }
