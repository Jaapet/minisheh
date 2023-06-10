/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 17:01:53 by ggualerz          #+#    #+#             */
/*   Updated: 2023/06/10 18:05:11 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H
# include "../minishell.h"
/* UTILS */
void	ft_init_pipes(t_ms *ms);
void	ft_close_pipes(t_ms *ms);
void	ft_lst_set_index(t_node *lst);
t_node	*ft_get_node(t_node *fnode, size_t i);
size_t	ft_lst_size(t_node *lst);
/* FD */
void	ft_assign_fd(t_ms *ms);
/* REDIR */
# define FLAG_INFILE_STD (O_RDONLY)
# define FLAG_OUTFILE_STD (O_TRUNC | O_CREAT | O_RDWR)
# define FLAG_OUTFILE_APPEND (O_WRONLY | O_CREAT | O_APPEND)
void	ft_set_redir(t_ms *ms);
/* EXEC */
#endif