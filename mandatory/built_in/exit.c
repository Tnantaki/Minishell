/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truangsi <truangsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:16:36 by truangsi          #+#    #+#             */
/*   Updated: 2023/06/16 13:09:38 by truangsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exit(char **arg)
{
	int	status;
	int	i;

	status = 0;
	i = 0;
	if (ft_2dstrlen(arg) > 1) //if there's one or more args (not only exit)
	{
		while (arg[1][i])
		{
			if (arg[1][0] == '+' || arg[1][0] == '-')
				break ;
			if (ft_isdigit(arg[1][i])) // if arg -> digit
				i++;
			else
				return (printf("exit\n"), 255);
		}
		if (ft_2dstrlen(arg) > 2) // if arg is digit, but there're more than two args
		{
			return (ft_prterr("exit:too many arguments\n"), 0);
		}
		status = ft_atoi(arg[1]); // if arg -> digit and it's the only arg
	}
	printf("exit\n");
	if (status > 255) // protect overflown
		status %= 256;
	return (status);
}