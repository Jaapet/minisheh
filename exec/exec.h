/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:01:53 by ggualerz          #+#    #+#             */
/*   Updated: 2023/07/09 15:49:22 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H
# include "../minishell.h"
/* UTILS */
void	ft_init_pipes(t_ms *ms);
void	ft_close_pipes(t_ms *ms);
void	ft_lst_set_index(t_exe *lst);
t_exe	*ft_get_node(t_exe *fnode, size_t i);
size_t	ft_lst_size(t_exe *lst);
/* FD */
void	ft_assign_fd(t_ms *ms);
/* REDIR */
# define FLAG_INFILE_STD (O_RDONLY)
# define FLAG_OUTFILE_STD (O_TRUNC | O_CREAT | O_RDWR)
# define FLAG_OUTFILE_APPEND (O_WRONLY | O_CREAT | O_APPEND)
void	ft_set_redir(t_ms *ms);
/* FORK */
void	ft_fork(t_ms *ms, char **envp, size_t cmd_i);
/* EXEC */
void	ft_exec(t_ms *ms, char **envp);
/* PATH */
char	**ft_parse_path(t_ms *ms);
/* ACCESS */
void ft_acess_cmd(t_ms *ms);
#endif
