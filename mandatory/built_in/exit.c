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

#define LONG_MAX 9223372036854775807

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
		if (nb >= LONG_MAX / 10 && (str[i - 1] > '0' || \
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
			return (ft_prterr("exit: too many arguments\n"), EXIT_FAILURE);
		if (!is_longint(arg[1], &status))
		{
			printf("exit\n");
			ft_prterrf("exit: ", arg[i], ": numeric argument required\n");
			restore_termios(&msh->term);
			free_msh(msh);
			ft_free2dstr(get_env());
			exit(ES_ERROR_EXIT);
		}
		i++;
	}
	printf("exit\n");
	restore_termios(&msh->term);
	ft_free2dstr(get_env());
	return (free_msh(msh), exit(status), EXIT_SUCCESS);
}
