/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:34:22 by ggualerz          #+#    #+#             */
/*   Updated: 2023/06/11 22:02:35 by ggualerz         ###   ########.fr       */
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
// COLORS
# define PUR "\033[0;35m"
# define CYA "\033[0;36m"
# define STD "\033[0m"
// NODE OF t_ms.node_lst
typedef struct s_node
{
	size_t			index;
	char			**cmd;
	bool			is_redir;
	char			redir_t;
	char			*i_file;
	char			*o_file;
	pid_t			pid;
	int				fd_i;
	int				fd_o;
	struct s_node	*next;
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


#endif