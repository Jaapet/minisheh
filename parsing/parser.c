/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 17:28:00 by ndesprez          #+#    #+#             */
/*   Updated: 2023/07/08 17:51:42 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	**proc(char *word)
{
	int		i;
	int		last_op;
	char	quote;
	char	**list;

	list = NULL;
	i = 0;
	last_op = 0;
	while (word[i])
	{
		quote = update_quote(quote, word[i]);
		if (word[i] == '|' && !quote)
			list = proc_pipe(list, word, &i, &last_op);
		else if ((word[i] == '<' || word[i] == '>') && !quote)
			list = proc_redir(list, word, &i, &last_op);
		i++;
	}
	if (i > last_op + 1)
		list = lst_add(list, proc_word(word, i, last_op));
	return (list);
}

static void	add_back(t_cmd **list, char *word, char **env)
{
	t_cmd	*new;
	t_cmd	*temp;

	temp = *list;
	if (!temp->word)
		temp->word = proc_quote(word, env);
	else
	{
		new = ft_calloc(1, sizeof(t_cmd));
		while (temp->next)
			temp = temp->next;
		temp->next = new;
		new->prev = temp;
		new->word = proc_quote(word, env);
	}
}

static void	add_cmd(t_cmd **list, char **words, char **env)
{
	int	i;

	i = 0;
	while (words[i])
	{
		add_back(list, words[i], env);
		i++;
	}
}

static t_cmd	*proc_cmds(char **cmds, char **env)
{
	t_cmd	*list;
	int		i;

	i = 0;
	list = ft_calloc(1, sizeof(t_cmd));
	while (cmds[i])
	{
		add_cmd(&list, proc(cmds[i]), env);
		i++;
	}
	return (list);
}

t_cmd	*parse(char *line, char **env)
{
	char	**cmds;
	t_cmd	*list;
	//if (!line) error
	cmds = split_line(line);
	if (!cmds)
		return (NULL);
	list = proc_cmds(cmds, env);
	if (!list)
		return (NULL);
	return (list);
}

// void	ft_lstprint(t_cmd *lst)
// {
// 	while (lst)
// 	{
// 		printf(" %s ->", lst->word);
// 		lst = lst->next;
// 	}
// 	printf(" NULL\n");
// }

// int	main(int argc, char **argv)
// {
// 	t_cmd	*clist;

// 	clist = parse("e\"cho\" toto << yop > a.txt | e'cho titi'");
// 	ft_lstprint(clist);
// 	system ("leaks minishell");
// }