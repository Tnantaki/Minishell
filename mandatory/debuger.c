/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debuger.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:29:03 by tnantaki          #+#    #+#             */
/*   Updated: 2023/06/12 13:29:04 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	debug_tokens(char **str)
{
	int	i;

	i = 0;
	printf("### Tokens ###\n");
	while (str[i])
	{
		printf("str[%d]:%s\n", i, str[i]);
		i++;
	}
	return (0);
}

int	debug_type(t_type *type, int nb_tk)
{
	int	i;

	i = 0;
	printf("### Token Type ###\n");
	while (i < nb_tk)
	{
		printf("type[%d]: ", i);
		if (type[i] == 1)
			printf("Redirection\n");
		else if (type[i] == 2)
			printf("Pipe\n");
		else if (type[i] == 3)
			printf("Filename\n");
		else if (type[i] == 4)
			printf("Argument\n");
		else
			printf("Error\n");
		i++;
	}
	return (0);
}

int	debug_spcmd(t_spcmd *spcmd, int nb_cmd)
{
	int	i;
	int	j;

	i = 0;
	printf("### Simple Command ###\n");
	while (i < nb_cmd)
	{
		printf("arg:%d, io:%d, pipe:%d\n",
			spcmd[i].nb.arg, spcmd[i].nb.io, spcmd[i].nb.pipe);
		printf("arg: ");
		j = 0;
		while (spcmd[i].arg[j])
		{
			printf("%s, ", spcmd[i].arg[j++]);
		}
		printf("\n");
		i++;
	}
	return (0);
}
