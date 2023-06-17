/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 17:28:00 by ndesprez          #+#    #+#             */
/*   Updated: 2023/06/14 19:47:26 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	proc_redir(t_node **node, char *cmd, int index)
{
	
}

static t_node	*create_node(char *cmd)
{
	t_node	*new;
	int		i;

	new = malloc(sizeof(t_node));
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
		new->cmd = ft_strtrim(cmd, " ");
	else
		proc_redir(&new, cmd, i);
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
