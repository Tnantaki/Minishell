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

// int	ft_exit(char **arg)
// {
// 	int	status;
// 	int	i;

// 	status = 0;
// 	i = 0;
// 	if (ft_2dstrlen(arg) > 2) // if arg is digit, but there're more than two args
// 		return (ft_prterr("exit: too many arguments\n"), 1);
// 	if (ft_2dstrlen(arg) > 1) //if there's one or more args (not only exit)
// 	{
// 		while (arg[1][i])
// 		{
// 			if (arg[1][0] == '+' || arg[1][0] == '-')
// 				break ;
// 			if (ft_isdigit(arg[1][i])) // if arg -> digit
// 				i++;
// 			else
// 				return (printf("exit\n"), 255);
// 		}
// 		status = atoi(arg[1]); // if arg -> digit and it's the only arg
// 	}
// 	free_msh(msh);
// 	printf("exit\n");
// 	exit(status %= 256);
// 	return (EXIT_SUCCESS);
// }

# define LONG_MAX 9223372036854775807

int	is_negative(char *str, int *i)
{
	int	negative;

	negative = 1;
	while ((str[*i] && str[*i] >= 9 && str[*i] <= 13) || str[*i] == ' ')
		(*i)++;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[(*i)++] == '-')
			negative = -1;
	}
	return (negative);
}

static bool	is_longint(char *str, int *status)
{
	int			i;
	long long	nb;
	int			negative;

	i = 0;
	nb = 0;
	negative = is_negative(str, &i);
	while (str[i] && ft_isdigit(str[i]))
	{
		if (nb >= LONG_MAX / 10 && (str[i - 1] > '0' ||
			(negative == 1 && str[i] > '7') || str[i] > '8'))
				return (false);
		nb = nb * 10 + (str[i++] - '0');
	}
	if (nb)
		return (*status = (nb * negative) % 256, true);
	return (false);
}

int	ft_exit(char **arg, t_msh *msh)
{
	int	status;
	int	i;

	status = 0;
	i = 1;
	while (arg[i])
	{
		if (i > 1)
			ft_prterr("exit: too many arguments\n");
		if (!is_longint(arg[1], &status))
		{
			printf("exit\n");
			ft_prterrf("exit: ", arg[i], ": numeric argument required\n");
			free_msh(msh);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	free_msh(msh);
	exit(status);
	return (EXIT_SUCCESS);
}