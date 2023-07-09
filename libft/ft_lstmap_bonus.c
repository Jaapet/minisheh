/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 11:04:24 by ggualerz          #+#    #+#             */
/*   Updated: 2023/06/14 17:21:13 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*out_lst;
	t_list	*temp_lst;

	if (lst == NULL)
		return (NULL);
	out_lst = NULL;
	while (lst)
	{
		temp_lst = ft_lstnew(f(lst->content));
		if (temp_lst == NULL)
		{
			ft_lstclear(&out_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&out_lst, temp_lst);
		lst = lst->next;
	}
	return (out_lst);
}
