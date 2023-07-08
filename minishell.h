/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:34:22 by ggualerz          #+#    #+#             */
/*   Updated: 2023/07/07 20:50:42 by ggualerz         ###   ########.fr       */
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
// Redir enum
enum	e_redir
{
	no_redir,
	in_simple,
	in_double,
	out_simple,
	out_double
};
// Redir elem
typedef struct s_redir
{
	enum e_redir	type; //n
	char			*file; //n si un here_doc, mettre le fichier heredoc voir avec g
}	t_redir;
// NODE OF t_ms.node_lst
typedef struct s_node
{
	size_t			index; //g
	char			**cmd; //n
	t_redir			*redir;
	pid_t			pid; //g
	int				fd_i; //g
	int				fd_o; //g
	struct s_node	*next; //n
}	t_node;
// MINISHELL SUPER STRUCTURE
typedef struct s_ms
{
	t_node	*node_lst;
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
t_node	*parse(char *line);
//BUILTIN
void	ft_pwd(void);
void	ft_cd(char *path, t_ms *ms);
void 	ft_echo(char **cmd);
void	ft_env(t_ms *ms);
void	ft_export(t_ms *ms, char **cmd);
void	ft_unset(t_ms *ms, char **cmd);
//BUILTIN UTILS
char 	**ft_dup_env(char **envp);
// bool	ft_is_in_env(t_ms *ms, char *varname);
//UTILS
void ft_printf_err(char* bin_name, char* args, char* err_msg);
#endif