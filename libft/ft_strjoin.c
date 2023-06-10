/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 06:43:18 by ggualerz          #+#    #+#             */
/*   Updated: 2023/03/29 05:40:05 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*out_str;

	out_str = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (out_str == NULL)
		return (NULL);
	ft_strlcpy(out_str, s1, ft_strlen(s1) + 1);
	ft_strlcpy(out_str + (ft_strlen(s1)), s2, ft_strlen(s2) + 1);
	return (out_str);
}
