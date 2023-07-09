/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:34:22 by ggualerz          #+#    #+#             */
/*   Updated: 2023/07/09 20:53:55 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <stdbool.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# define BASH_NAME_ERR	"minisheh: "
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
// Lexer chain list
typedef struct s_lex
{
	char			*word;
	t_type			type;
	struct s_lex	*next;
	struct s_lex	*prev;
}	t_lex;
// Redir struct
typedef struct s_redir
{
	size_t	index;
	char	*arg;
	t_type	type;
} t_redir;
// Exec chain list
typedef struct s_exe
{
	size_t			index; //g
	bool			is_builtin; // flag qui defini si c'est un builtin
	bool			env_related; //flag qui defini en gros si ca doit etre forke lors d'une seule commande
	char			**cmd; //n
	t_redir			*redir; // array de redirection terminant par null
	pid_t			pid; //g
	int				fd_i; //g
	int				fd_o; //g
	struct s_exe	*next; //n
}	t_exe;
// MINISHELL SUPER STRUCTURE
typedef struct s_ms
{
	t_lex	*lex_first; //list chaine du lexer
	t_exe	*exe_first; //list chainee des exe
	char	**envp;
	size_t	cmd_nb;
	int		*pipes;
}	t_ms;



#endif