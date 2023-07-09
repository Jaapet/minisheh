/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 05:59:12 by ggualerz          #+#    #+#             */
/*   Updated: 2023/06/14 17:23:46 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*out_str;

	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	out_str = ft_calloc(len + 1, sizeof(char));
	if (out_str == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (out_str);
	ft_strlcpy(out_str, s + start, len + 1);
	return (out_str);
}
