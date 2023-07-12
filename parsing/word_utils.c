/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:14:53 by ndesprez          #+#    #+#             */
/*   Updated: 2023/07/12 23:57:54 by ggualerz         ###   ########.fr       */
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
	free_ptr(word);
	return (new);
}

static char	*expand(char *word, char **env)
{
	char	*var;
	int		i;
	char	quote;

	i = 0;
	quote = 0;
	while (word[i])
	{
		quote = update_quote(quote, word[i]);
		if (word[i] == '$' && is_valid_char(word[i + 1]) && quote != '\'')
		{
			if (word[i + 1] == '?')
			{
				var = ft_itoa(g_ms->last_errcode);
				word = replace_var(word, var, i, 2);
				i += ft_strlen(var) - 1;
				free_ptr(var);
			}
			else
				word = expand2(word, &i, env);
		}
		i++;
	}
	return (word);
}

char	*proc_quote(char *word, char **env)
{
	char	quote;
	int		i;
	int		count;
	char	*new;

	i = 0;
	quote = 0;
	count = 0;
	new = expand(word, env);
	while (new[i])
	{
		if ((new[i] == '\'' || new[i] == '"') && !quote)
			count++;
		quote = update_quote(quote, new[i]);
		i++;
	}
	new = rem_quotes(new, count);
	return (new);
}

// int	main(void)
// {
// 	char	*env[3];

// 	env[0] = "toto=42";
// 	env[1] = "titi=@#$#@";
// 	env[2] = NULL;
// 	printf("%s\n",
// 		proc_quote("ab\"'c'\"de' f'gabc'$toto r'\"$titi k$fg iuhiu\"", env));
// }
