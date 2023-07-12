/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:23:09 by ggualerz          #+#    #+#             */
/*   Updated: 2023/07/12 19:45:22 by ndesprez         ###   ########.fr       */
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
char	*ft_isolate_val(char *full_var);
bool	ft_var_in_env(char **env, char *var);
bool	ft_var_syntax(char *bin_name, char *var);
char	*ft_get_env_value(char **env, char *var);
#endif