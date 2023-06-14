/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:25:51 by ggualerz          #+#    #+#             */
/*   Updated: 2023/06/14 17:24:13 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"

void	ft_rm_old_nl(t_list **lst)
{
	t_list	*last;
	t_list	*node;
	int		i;
	int		j;

	node = malloc(sizeof(t_list));
	if (lst == NULL || node == NULL)
		return ;
	node->next = NULL;
	last = ft_lstgetend(*lst);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content[i] && last->content[i] == '\n')
		i++;
	node->content = malloc(8 * ((ft_strlen_gnl(last->content) - i) + 1));
	if (node->content == NULL)
		return ;
	j = 0;
	while (last->content[i])
		node->content[j++] = last->content[i++];
	node->content[j] = '\0';
	ft_lstclearall(*lst);
	*lst = node;
}

void	ft_get_line(t_list *lst, char **line)
{
	int	i;
	int	j;

	if (lst == NULL)
		return ;
	ft_makeline(line, lst);
	if (*line == NULL)
		return ;
	j = 0;
	while (lst)
	{
		i = 0;
		while (lst->content[i])
		{
			if (lst->content[i] == '\n')
			{
				(*line)[j++] = lst->content[i];
				break ;
			}
			(*line)[j++] = lst->content[i++];
		}
		lst = lst->next;
	}
	(*line)[j] = '\0';
}

void	ft_lstaddback(t_list **lst, char *buffer, int red_bytes)
{
	int		i;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	new_node->content = malloc(sizeof(char) * (red_bytes + 1));
	if (new_node->content == NULL)
		return ;
	i = 0;
	while (buffer[i] && i < red_bytes)
	{
		new_node->content[i] = buffer[i];
		i++;
	}
	new_node->content[i] = '\0';
	if (*lst == NULL)
	{
		*lst = new_node;
		return ;
	}
	(ft_lstgetend(*lst))->next = new_node;
}

void	ft_read_to_lst(int fd, t_list **lst)
{
	char	*buffer;
	int		red_bytes;

	red_bytes = 1;
	while (ft_search_nl(*lst) == 0 && red_bytes != 0)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buffer == NULL)
			return ;
		red_bytes = read(fd, buffer, BUFFER_SIZE);
		if ((*lst == NULL && red_bytes == 0) || red_bytes == -1)
		{
			free(buffer);
			return ;
		}
		buffer[red_bytes] = '\0';
		ft_lstaddback(lst, buffer, red_bytes);
		free(buffer);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*lst = NULL;
	char			*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (ft_lstclearall(lst), lst = NULL, NULL);
	ft_read_to_lst(fd, &lst);
	if (lst == NULL)
		return (NULL);
	ft_get_line(lst, &line);
	ft_rm_old_nl(&lst);
	if (line[0] == '\0')
	{
		ft_lstclearall(lst);
		lst = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}
