/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:34:22 by ggualerz          #+#    #+#             */
/*   Updated: 2023/07/09 19:56:22 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <stdbool.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

# include "libft/includes/libft.h"
// TEMPORARY
# define ERR_DUMMY 1
// REDIRECTION DEFINES (OBSOLETE)
# define RD_I_S 1
# define RD_I_D 2
# define RD_O_S 3
# define RD_O_D 4
// BOOL
# define TRUE 1
# define FALSE 0
// type enum
typedef enum e_type
{
	undefined,
	is_pipe,
	si_redir,
	di_redir,
	so_redir,
	do_redir,
	is_file,
	is_command,
	is_arg
}	t_type;

typedef struct s_cmd
{
	char			*word;
	t_type			type;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}	t_cmd;

// MINISHELL SUPER STRUCTURE
typedef struct s_ms
{
	//t_node	*node_lst;
	char	**envp;
	size_t	node_nb;
	int		*pipes;
	char	*prompt;
}	t_ms;
// EXEC
void	ft_exec(t_ms *ms, char **envp);
// SEXY
void	ft_banner(void);
char *ft_prompt_str (char **env);
// PARSING
//t_node	*parse(char *line);

#endif