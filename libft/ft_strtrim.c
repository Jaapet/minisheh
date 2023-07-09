/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 06:58:27 by ggualerz          #+#    #+#             */
/*   Updated: 2023/06/14 17:23:43 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	ft_char_is_set(char const c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start_index;
	int		end_index;
	char	*trimmed_str;

	start_index = 0;
	while (ft_char_is_set(s1[start_index], set))
		start_index++;
	end_index = ft_strlen(s1) - 1;
	if (end_index < 0)
		return (ft_strdup(""));
	while (ft_char_is_set(s1[end_index], set))
		end_index--;
	trimmed_str = ft_substr(s1, start_index, end_index - start_index + 1);
	return (trimmed_str);
}
