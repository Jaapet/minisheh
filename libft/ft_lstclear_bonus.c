/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 20:39:59 by ggualerz          #+#    #+#             */
/*   Updated: 2023/06/14 17:20:59 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next_ptr;

	if (lst == NULL || *lst == NULL)
		return ;
	while (lst && *lst)
	{
		next_ptr = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = next_ptr;
	}
	*lst = NULL;
}
