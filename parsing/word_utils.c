/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:14:53 by ndesprez          #+#    #+#             */
/*   Updated: 2023/07/08 18:33:40 by ndesprez         ###   ########.fr       */
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

char	*ft_get_env_value(char **env, char *var)
{
	size_t	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], var, ft_strlen(var)) == 0
			&& env[i][ft_strlen(var)] == '=')
			return (ft_strdup(ft_strchr(env[i], '=') + 1));
		else if (ft_strncmp(env[i], var, ft_strlen(var)) == 0
			&& env[i][ft_strlen(var)] == '\0')
			return (NULL);
		i++;
	}
	return (NULL);
}

static char	*expand(char *word, char **env)
{
	char	*new;
	char	*var;
	int		i;
	int		j;
	char	quote;

	i = 0;
	quote = 0;
	while (word[i])
	{
		quote = update_quote(quote, word[i]);
		if (word[i] == '$' && quote != '\'')
		{
			j = 1;
			while (word[i + j] && is_valid_char(word[i + j]))//alnum + _
				j++;
			if (j > 1)
			{
				var = set_var(word, i, j, env);//
				new = replace_var(new, var, j);//
			}
		}
		i++;
	}
	return (new);
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
	while (word[i])
	{
		if ((word[i] == '\'' || word[i] == '"') && !quote)
			count++;
		quote = update_quote(quote, word[i]);
		i++;
	}
	new = expand(word, env);
	new = rem_quotes(word, count);
	return (new);
}

// int	main(void)
// {
// 	printf("%s\n", proc_quote("ab\"'c'\"de' f'g"));
// }
