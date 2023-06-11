/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggualerz <ggualerz@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:36:47 by ggualerz          #+#    #+#             */
/*   Updated: 2023/06/10 19:26:47 by ggualerz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <readline/readline.h>

int main(int ac, char **av, char **env)
{
	printf("%s\n  __  __ _       _  _____ _          _\n |  \\/  (_)   ", PUR);
	printf("  (_)/ ____| |        | |\n | \\  / |_ _ __  _| (___ | |__");
	printf("   ___| |__\n | |\\/| | | '_ \\| |\\___ \\| '_ \\ / _ \\ '_ \\");
	printf("\n | |  | | | | | | |____) | | | |  __/ | | |\n |_|  |_|_|_| |_|_");
	printf("|_____/|_| |_|\\___|_| |_|\n");
	printf("%s\t     ndesprez X ggualerz\n%s", CYA, STD);
	while (1)
	{
		printf("\n%s", readline("\033[0;35mMiniSheh>\033[0m"));
	}
}