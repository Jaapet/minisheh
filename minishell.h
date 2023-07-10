/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:34:22 by ggualerz          #+#    #+#             */
/*   Updated: 2023/07/10 22:35:52 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <stdbool.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
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
	char	*prompt;

	bool	in_exec;
	bool	in_heredoc;
	pid_t		heredoc_pid;
	
	int		last_errcode;
}	t_ms;

t_ms	*g_ms;

// EXEC
void	ft_exec(t_ms *ms, char **envp);
// SEXY
void	ft_banner(void);
char *ft_prompt_str (char **env);
//BUILTIN
int	ft_pwd(void);
int	ft_cd(char *path, t_ms *ms);
int ft_echo(char **cmd);
int	ft_env(t_ms *ms);
int	ft_export(t_ms *ms, char **cmd);
int	ft_unset(t_ms *ms, char **cmd);
void	ft_builtin_exit(t_ms *ms, char *cmd);
//PARSE
t_lex	*parse(char *line, char **env);
//BUILTIN UTILS
char 	**ft_dup_env(char **envp);
// bool	ft_is_in_env(t_ms *ms, char *varname);
//UTILS
void ft_printf_err(char* bin_name, char* args, char* err_msg);
char *ft_str_tolower(char *str);
//CLEAN
void ft_clean_tab(char **tab);
//SIGNALS
void	handle(void);
void	control_bs(int var);
void	control_c(int var);
//READLINE
void	rl_replace_line(const char *text, int clear_undo);
#endif