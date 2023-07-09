/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndesprez <ndesprez@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 19:34:32 by ndesprez          #+#    #+#             */
/*   Updated: 2023/07/09 19:35:18 by ndesprez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_op(char c)
{
	if (c == '|' || c == '<' || c == '>')
		return (1);
	return (0);
}

int	redir_ok(char a, char b)
{
	if ((a == '<' || a == '>') && a == b)
		return (0);
	return (1);
}