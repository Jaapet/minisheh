/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 17:27:51 by ndesprez          #+#    #+#             */
/*   Updated: 2023/07/06 15:11:53 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../minishell.h"

char	update_quote(char quote, char cur);
char	**split_line(char *line);
char	*proc_word(char *word, int i, int last_op);
char	**proc_pipe(char **list, char *word, int *i, int *last_op);


#endif