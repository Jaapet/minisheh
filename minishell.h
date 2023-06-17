/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:34:22 by ggualerz          #+#    #+#             */
/*   Updated: 2023/06/17 16:35:22 by ggualerz         ###   ########.fr       */
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
// REDIRECTION DEFINES
# define RD_I_S 1
# define RD_I_D 2
# define RD_O_S 3
# define RD_O_D 4
// BOOL
# define TRUE 1
# define FALSE 0
// NODE OF t_ms.node_lst
typedef struct s_node
{
	size_t			index; //g
	char			**cmd; //n
	bool			is_redir; //n
	char			redir_t; //n
	char			*i_file; //n
	char			*o_file; //n
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
}	t_ms;
// EXEC
void	ft_exec(t_ms *ms, char **envp);
// SEXY
void	ft_banner(void);
// PARSING
t_node	*parse(char *line);

#endif