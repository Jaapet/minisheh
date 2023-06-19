/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 17:28:00 by ndesprez          #+#    #+#             */
/*   Updated: 2023/06/19 20:21:42 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_node	*create_node(char *cmd)
{
	t_node	*new;
	int		i;

	new = ft_calloc(1, sizeof(t_node));
	if (!new)
		return (NULL);
	new->next = NULL;
	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '<' || cmd[i] == '>')
			break ;
		i++;
	}
	if (i == ft_strlen(cmd))
		set_cmd(&new, cmd, 0, i);
	else
		proc_redir(&new, cmd);
	return (new);
}

static void	add_node(t_node **list, char *cmd)
{
	t_node	*new;
	t_node	*last;

	new = create_node(cmd);
	if (!new)
		return ;
	if (!*list)
	{
		*list = new;
		return ;
	}
	last = *list;
	while (last->next)
		last = last->next;
	last->next = new;
}

static t_node	*proc_cmds(char **cmds)
{
	int		i;
	t_node	*list;

	i = 0;
	while (cmds[i])
	{
		add_node(&list, cmds[i]);
		i++;
	}
	return (list);
}

t_node	*parse(char *line)
{
	char	**cmds;
	t_node	*list;
	//if (!line) error
	cmds = split_line(line);
	//if (!cmds) malloc prot
	list = proc_cmds(cmds);
	return (list);
}
