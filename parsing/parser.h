/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 17:27:51 by ndesprez          #+#    #+#             */
/*   Updated: 2023/07/12 20:47:02 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../minishell.h"

char	update_quote(char quote, char cur);
char	**split_line(char *line);
char	*proc_word(char *word, int i, int last_op);
char	**proc_pipe(char **list, char *word, int *i, int *last_op);
char	**proc_redir(char **list, char *word, int *i, int *last_op);
char	**lst_add(char **list, char *word);
char	*proc_quote(char *word, char **env);
int		is_valid_char(char c);
char	*set_var(char *word, int beg, int size, char **env);
char	*replace_var(char *word, char *var, int beg, int size);
void	tokenize(t_lex **list);
void	set_type(t_lex *word, t_type type);
int		is_op(char c);
int		redir_ok(char a, char b);
void	free_tab(char **tab);
char	*expand2(char *word, int *i, char **env);

t_lex	*parse(char *line, char **env);

#endif