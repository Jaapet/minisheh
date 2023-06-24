/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 18:51:59 by ggualerz          #+#    #+#             */
/*   Updated: 2023/06/24 20:03:28 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

// bool	ft_syntax(char *cmd)
// {
// 	L'identifiant doit commencer par une lettre (a-z ou A-Z).
// Les caractères suivants peuvent être des lettres (a-z ou A-Z), des chiffres (0-9) ou le caractère souligné (_).
// Les caractères spéciaux tels que l'espace, les symboles de ponctuation et les caractères de contrôle ne sont pas autorisés.
// }

void	ft_unset(t_ms *ms, char **cmd)
{
	size_t i;

	i = 1;
	while (cmd[i])
	{
		//check syntax before, pas de =
		ft_rm_env(ms, cmd[i]);
		i++;
	}
	
}