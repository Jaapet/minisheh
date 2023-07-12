/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:53:40 by ndesprez          #+#    #+#             */
/*   Updated: 2023/07/12 21:32:01 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_valid_char(char c)
{
	if (ft_isalnum(c) || c == '_' || c == '?')
		return (1);
	return (0);
}

static char	*ft_get_env_value(char **env, char *var)
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

char	*set_var(char *word, int beg, int size, char **env)
{
	char	*name;
	char	*var;
	int		i;

	name = ft_calloc(size, sizeof(char));
	if (!name)
		return (NULL);
	i = 0;
	while (i < size - 1)
	{
		name[i] = word[beg + i + 1];
		i++;
	}
	var = ft_get_env_value(env, name);
	if (!var)
		return (ft_strdup(""));
	free(name);
	return (var);
}

char	*replace_var(char *word, char *var, int beg, int size)
{
	char	*new;
	int		*iterators;

	new = ft_calloc((ft_strlen(word) - size) + ft_strlen(var) + 1,
			sizeof(char));
	iterators = ft_calloc(2, sizeof(int));
	while (iterators[0] < beg)
	{
		new[iterators[0]] = word[iterators[0]];
		iterators[0]++;
	}
	while (var[iterators[1]])
	{
		new[iterators[0]] = var[iterators[1]];
		iterators[0]++;
		iterators[1]++;
	}
	iterators[1] = beg + size;
	while (word[iterators[1]])
	{
		new[iterators[0]] = word[iterators[1]];
		iterators[0]++;
		iterators[1]++;
	}
	return (free(word), new);
}

// int	main(void)
// {
// 	char	*env[2];
// 	char	*var;
// 	char	*word;

// 	env[0] = "toto=42";
// 	var = set_var("abc$toto r", 3, 5, env);
// 	printf("%s\n", var);
// 	word = replace_var("abc$toto r", var, 3, 5);
// 	printf("%s\n", word);
// }
