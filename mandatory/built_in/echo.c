/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prachman <prachman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:21:59 by prachman          #+#    #+#             */
/*   Updated: 2023/06/08 22:10:21 by prachman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int check_str(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_strcmp(&str[i], "\"") == 0)
			return (1);
	}
	return (0);
}

int ft_echo(char **arg)
{
	int i;
	int	j;
	int flag;
	
	i = 1;
	flag = 0;
	if (ft_strcmp(arg[1], "-n") == 0)
	{
		i = 2;       
		flag = 1;
	}
	while (arg[i])
	{
		if (arg[i][0] == '\"' && arg[i][ft_strlen(arg[i]) - 1] == '\"') //check if the string has \"
		{
			j = 1;
			while (arg[i][j] && (size_t)j < ft_strlen(arg[i]) - 1) //only print to the char before "
			{
				printf("%c", arg[i][j]);
				j++;
			}
		}
		else
			printf("%s", arg[i]);
		i++;
		if (arg[i])
			printf(" ");
	}
	if (!flag)
		printf("\n");
	return (EXIT_SUCCESS);
}