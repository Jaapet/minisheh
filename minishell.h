/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 15:34:22 by ggualerz          #+#    #+#             */
/*   Updated: 2023/06/10 18:17:25 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <stdbool.h>
# include <fcntl.h>
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
// MINISHELL SUPER STRUCTURE
typedef struct s_ms
{
	t_node	*node_lst;
	char	**envp;
	size_t	node_nb;
	int		*pipes;
} t_ms;
// NODE OF t_ms.node_lst
typedef	struct s_node
{
	size_t	index;
	char	**cmd;
	bool	is_redir;
	char	redir_t;
	char	*i_file;
	char	*o_file;
	pid_t	pid;
	int		fd_i;
	int		fd_o;
	t_node	*next;
}	t_node;


#endif