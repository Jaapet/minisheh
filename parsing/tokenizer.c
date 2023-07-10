/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 17:50:17 by ndesprez          #+#    #+#             */
/*   Updated: 2023/07/10 23:15:42 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	set_pipes(t_lex **list)
{
	t_lex	*temp;

	temp = *list;
	while (temp)
	{
		if (!ft_strncmp(temp->word, "|", 2))
			temp->type = is_pipe;
		temp = temp->next;
	}
}

static void	set_redir(t_lex **list)
{
	t_lex	*temp;

	temp = *list;
	while (temp)
	{
		if (!ft_strncmp(temp->word, ">", 2))
			temp->type = so_redir;
		else if (!ft_strncmp(temp->word, ">>", 3))
			temp->type = do_redir;
		else if (!ft_strncmp(temp->word, "<", 2))
			temp->type = si_redir;
		else if (!ft_strncmp(temp->word, "<<", 3))
			temp->type = di_redir;
		if (temp->type >= si_redir && temp->type <= do_redir
			&& temp->next && !temp->next->type)
			temp->next->type = is_file;
		temp = temp->next;
	}
}

static void	set_cmds(t_lex **list)
{
	t_lex	*temp;
	int		pipe;

	temp = *list;
	pipe = 1;
	while (temp)
	{
		if (temp->type == is_pipe)
			pipe = 1;
		if (temp->type == undefined && pipe)
		{
			temp->type = is_command;
			pipe = 0;
		}
		temp = temp->next;
	}
}

static void	set_args(t_lex **list)
{
	t_lex	*temp;

	temp = *list;
	while (temp)
	{
		if (temp->type == undefined)
			temp->type = is_arg;
		temp = temp->next;
	}
}

void	tokenize(t_lex **list)
{
	set_pipes(list);
	set_redir(list);
	set_cmds(list);
	set_args(list);
}

// void	ft_lstprint(t_lex *lst)
// {
// 	while (lst)
// 	{
// 		printf("%s : ", lst->word);
// 		printf("%u -> ", lst->type);
// 		lst = lst->next;
// 	}
// 	printf(" NULL\n");
// }

// int	main(void)
// {
// 	t_lex	*clist;
// 	char	**env;

// 	clist = parse("echo 'toto' >> a.txt | rev | cat -e", env);
// 	ft_lstprint(clist);
// 	//system ("leaks minishell");
// }
// int	main(void)
// {
// 	return (0);
// }
