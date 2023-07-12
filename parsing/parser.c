/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 17:28:00 by ndesprez          #+#    #+#             */
/*   Updated: 2023/07/11 23:33:18 by ndesprez         ###   ########.fr       */
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
	if (i > last_op + 1
		|| (i == 1 && word[0] != '|' && word[0] != '<' && word[0] != '>'))
		list = lst_add(list, proc_word(word, i, last_op));//
	free(word);
	return (list);
}

static void	add_back(t_lex **list, char *word, char **env)
{
	t_lex	*new;
	t_lex	*temp;

	temp = *list;
	if (!temp->word)
		temp->word = proc_quote(word, env);
	else
	{
		new = ft_calloc(1, sizeof(t_lex));
		while (temp->next)
			temp = temp->next;
		temp->next = new;
		new->prev = temp;
		new->word = proc_quote(word, env);
	}
}

static void	add_cmd(t_lex **list, char **words, char **env)
{
	int	i;

	i = 0;
	while (words[i])
	{
		add_back(list, words[i], env);
		i++;
	}
	free(words);
}

static t_lex	*proc_cmds(char **cmds, char **env)
{
	t_lex	*list;
	int		i;

	i = 0;
	list = ft_calloc(1, sizeof(t_lex));
	while (cmds[i])
	{
		add_cmd(&list, proc(cmds[i]), env);
		i++;
	}
	free(cmds);
	return (list);
}

t_lex	*parse(char *line, char **env)
{
	char	**cmds;
	t_lex	*list;

	cmds = split_line(line);
	if (!cmds)
		return (NULL);
	list = proc_cmds(cmds, env);
	if (!list)
		return (NULL);
	tokenize(&list);
	return (list);
}

// void	ft_lstprint(t_lex *lst)
// {
// 	while (lst)
// 	{
// 		printf(" %s ->", lst->word);
// 		lst = lst->next;
// 	}
// 	printf(" NULL\n");
// }

// int	main(void)
// {
// 	t_lex	*clist;
// 	char	*env[3];

// 	env[0] = "e=/bin/echo";
// 	env[1] = "titi=";
// 	env[2] = NULL;

// 	clist = parse("> a.txt $e | r'ev$' | rev$ | $titi", env);
// 	system ("leaks minishell");
// 	ft_lstprint(clist);
// }
