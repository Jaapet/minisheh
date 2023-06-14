/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 21:44:03 by ggualerz          #+#    #+#             */
/*   Updated: 2023/06/14 17:21:06 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*next_ptr;

	while (lst)
	{
		next_ptr = lst->next;
		(*f)(lst->content);
		lst = next_ptr;
	}
}
