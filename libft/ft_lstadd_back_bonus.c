/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 20:23:00 by ggualerz          #+#    #+#             */
/*   Updated: 2023/06/14 17:20:52 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (lst)
	{
		if (*lst)
			(ft_lstlast(*lst))->next = new;
		else
			*lst = new;
	}
}
