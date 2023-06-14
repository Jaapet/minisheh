/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 05:47:58 by ggualerz          #+#    #+#             */
/*   Updated: 2023/06/14 17:22:55 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	s_len;
	char	*out_str;

	s_len = ft_strlen(s1);
	out_str = ft_calloc(s_len + 1, sizeof(char));
	if (out_str == NULL)
		return (NULL);
	ft_strlcpy(out_str, s1, s_len + 1);
	return (out_str);
}
