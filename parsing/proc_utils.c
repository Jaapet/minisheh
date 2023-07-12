/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 15:13:57 by ndesprez          #+#    #+#             */
/*   Updated: 2023/07/12 23:57:54 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	**lst_add(char **list, char *word)
{
	int		i;
	char	**new;

	i = 0;
	if (!list)
	{
		new = ft_calloc(2, sizeof(char *));
		if (!new)
			return (NULL);
		new[0] = word;
	}
	else
	{
		while (list[i])
			i++;
		new = ft_calloc(i + 2, sizeof(char *));
		if (!new)
			return (NULL);
		new[i] = word;
		while (i-- > 0)
			new[i] = list[i];
	}
	free_ptr(list);
	return (new);
}

char	*proc_word(char *word, int i, int last_op)
{
	char	*new;
	int		j;

	if (!last_op || i - last_op > 1)
	{
		if (last_op)
		{
			new = ft_calloc(i - last_op, sizeof(char));
			last_op++;
		}
		else
			new = ft_calloc(i - last_op + 1, sizeof(char));
		if (!last_op && i > 1 && is_op(word[0]) && redir_ok(word[0], word[1]))
			last_op++;
		j = 0;
		while (last_op < i)
		{
			new[j] = word[last_op];
			j++;
			last_op++;
		}
	}
	else
		return (NULL);
	return (new);
}

char	**proc_pipe(char **list, char *word, int *i, int *last_op)
{
	if (*i && *i > (*last_op) + 1)
		list = lst_add(list, proc_word(word, *i, *last_op));
	list = lst_add(list, proc_word(word, *i + 1, *i - 1));
	*last_op = *i;
	return (list);
}

char	**proc_redir(char **list, char *word, int *i, int *last_op)
{
	if (*i && *i > (*last_op) + 1)
		list = lst_add(list, proc_word(word, *i, *last_op));
	if ((word[*i] == '>' && word[(*i) + 1] == '>')
		|| (word[*i] == '<' && word[(*i) + 1] == '<'))
	{
		list = lst_add(list, proc_word(word, *i + 2, *i - 1));
		(*i)++;
	}
	else
		list = lst_add(list, proc_word(word, *i + 1, *i - 1));
	*last_op = *i;
	return (list);
}

// int	main(int argc, char **argv)
// {
// 	char	**list;
// 	char	*a;
// 	char	*b;
// 	char	*c;
// 	int		i;
// 	int		last_op;

// 	a = ft_calloc(7, sizeof(char));
// 	b = ft_calloc(2, sizeof(char));
// 	c = ft_calloc(5, sizeof(char));
// 	a[0] = 'a';
// 	a[1] = 'b';
// 	a[2] = '<';
// 	a[3] = '<';
// 	a[4] = 'd';
// 	a[5] = 'e';
// 	i = 2;
// 	last_op = 0;
// 	list = proc_redir(list, a, &i, &last_op);
// 	printf("%s, %s, %s\n", list[0], list[1], list[2]);
// 	printf("%d, %d\n", i, last_op);
// 	//system ("leaks a.out");
// }