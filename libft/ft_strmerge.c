/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmerge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 05:52:29 by ggualerz          #+#    #+#             */
/*   Updated: 2023/06/14 17:23:27 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmerge(char *s1, char *s2, char del_source)
{
	char	*out_str;

	out_str = ft_calloc(ft_strlen(s2) + ft_strlen(s1) + 1, sizeof(char));
	if (out_str == NULL)
		return (NULL);
	ft_strlcat(out_str, s1, ft_strlen(s1) + 1);
	ft_strlcat(out_str, s2, ft_strlen(s2) + ft_strlen(s1) + 1);
	if (del_source != 0)
	{
		free(s1);
		free(s2);
	}
	return (out_str);
}
