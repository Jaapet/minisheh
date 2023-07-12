/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:01:53 by ggualerz          #+#    #+#             */
/*   Updated: 2023/07/12 20:58:58 by ggualerz         ###   ########.fr       */
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
void	ft_set_redir(t_ms *ms);
/* FORK */
void	ft_fork(t_ms *ms, char **envp, size_t cmd_i);
/* EXEC */
void	ft_exec(t_ms *ms, char **envp);
/* PATH */
char	**ft_parse_path(t_ms *ms);
/* ACCESS */
void	ft_acess_cmd(t_ms *ms);
/* REDIRECTIONS */
void	ft_siredir(t_exe *lst, size_t i);
void	ft_diredir(t_exe *lst, size_t i);
void	ft_soredir(t_exe *lst, size_t i);
void	ft_doredir(t_exe *lst, size_t i);
int		ft_open_heredoc(char *delim);

void	ft_init_exec(t_ms *ms);
size_t	ft_lex_to_exe_redir_count(t_lex *last_pipe);
size_t	ft_cargs(t_lex *begin);
void	ft_lex_to_exe_redir(t_exe *curr_exe, t_lex *curr_lex);
#endif
