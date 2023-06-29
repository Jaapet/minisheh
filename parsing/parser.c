/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 17:28:00 by ndesprez          #+#    #+#             */
/*   Updated: 2023/06/29 20:53:39 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	**proc(char *word)
{
	int		i;
	char	quote;
	char	**list;

	while (word[i])
	{
		quote = update_quote(quote, word[i]);
		if (word[i] == '|' && !quote)
		{
			
		}
	}
}

static t_cmd	*proc_cmds(char **cmds)
{
	t_cmd	*list;
	int		i;

	i = 0;
	while (cmds[i])
	{
		add_cmd(&list, proc(cmds[i]));
		i++;
	}
	return (list);
}

t_cmd	*parse(char *line)
{
	char	**cmds;
	t_cmd	*list;
	//if (!line) error
	cmds = split_line(line);
	//if (!cmds) malloc prot
	list = proc_cmds(cmds);
	return (list);
}
