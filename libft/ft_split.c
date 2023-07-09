/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 06:22:43 by ggualerz          #+#    #+#             */
/*   Updated: 2023/06/14 17:22:42 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static size_t	ft_next_c(const char *s, char c)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	ft_count_items(const char *s, char c)
{
	size_t	items_count;
	size_t	i;

	items_count = 0;
	i = 0;
	while (i < ft_strlen(s))
	{
		if (ft_next_c(s + i, c) != 0)
		{
			items_count++;
			i += ft_next_c(s + i, c);
		}
		else
			i++;
	}
	return (items_count);
}

static void	ft_clean_array(char **array_to_clean)
{
	size_t	i;

	i = 0;
	while (array_to_clean[i] != NULL)
	{
		free(array_to_clean[i]);
		i++;
	}
	free(array_to_clean);
}

char	**ft_split(char const *s, char c)
{
	size_t	i[2];
	char	**out_array;

	out_array = ft_calloc(ft_count_items(s, c) + 1, sizeof(char *));
	if (out_array == NULL)
		return (NULL);
	ft_bzero(i, sizeof(size_t) * 2);
	while (i[0] < ft_strlen(s))
	{
		if (ft_next_c(s + i[0], c) != 0)
		{
			out_array[i[1]] = ft_substr(s, i[0], ft_next_c(s + i[0], c));
			if (out_array[i[1]] == NULL)
			{
				ft_clean_array(out_array);
				return (NULL);
			}
			i[1]++;
			i[0] += ft_next_c(s + i[0], c);
		}
		else
			i[0]++;
	}
	out_array[i[1]] = NULL;
	return (out_array);
}
