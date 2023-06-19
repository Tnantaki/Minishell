/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truangsi <truangsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:21:59 by prachman          #+#    #+#             */
/*   Updated: 2023/06/15 14:33:59 by truangsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_echo(char **arg)
{
	int i;
	int flag;

	i = 1;
	flag = 0;
	if (!arg[1])
		return (printf("\n"), EXIT_SUCCESS);
	if (ft_strcmp(arg[1], "-n") == 0)
	{
		i = 2;
		flag = 1;
	}
	while (arg[i])
	{
		printf("%s", arg[i]);
		i++;
		if (arg[i])
			printf(" ");
	}
	if (!flag)
		printf("\n");
	return (EXIT_SUCCESS);
}