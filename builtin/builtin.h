/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:23:09 by ggualerz          #+#    #+#             */
/*   Updated: 2023/06/24 20:19:21 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H
# include "../minishell.h"
# include <stdbool.h>
size_t	ft_get_env_size(char **envp);
void	ft_free_env(t_ms *ms);
void	ft_add_env(t_ms *ms, char *export_arg);
void	ft_rm_env(t_ms *ms, char *unset_arg);
char	*ft_isolate_var(char *full_var);
#endif