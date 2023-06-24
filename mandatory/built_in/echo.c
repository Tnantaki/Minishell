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

int	ft_echo(char **arg)
{
	int	i;
	int	flag;

	i = 1;
	flag = 0;
	if (!arg[1])
		return (write(STDOUT_FILENO, "\n", 1), EXIT_SUCCESS);
	if (ft_strcmp(arg[1], "-n") == 0)
	{
		i = 2;
		flag = 1;
	}
	while (arg[i])
	{
		ft_putstr_fd(arg[i], STDOUT_FILENO);
		i++;
		if (arg[i])
			write(STDOUT_FILENO, " ", 1);
	}
	if (!flag)
		write(STDOUT_FILENO, "\n", 1);
	return (EXIT_SUCCESS);
}
