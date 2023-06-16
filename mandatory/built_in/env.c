/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truangsi <truangsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:16:04 by truangsi          #+#    #+#             */
/*   Updated: 2023/06/16 10:16:05 by truangsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	store_env(t_buin_cmd *buin)
{
	int			i;
	char    	**env;

	i = 0;
	env = get_env();
	while (env[i])
		i++;
	buin->env = (char **)malloc(sizeof(char *) * i + 1);
	if (!buin->env) //probably need to quit the process
		return (EXIT_FAILURE);
	i = 0;
	while (env[i])
	{
		buin->env[i] = env[i];
		i++;
	}
	return (EXIT_SUCCESS);
}

// int ft_env(char **arg, t_buin_cmd *buin)
int ft_env()
{
	int			i;
	char		**env;

	env = get_env();
	i = 0;
	while(env[i])
	{
		if (env[i] != NULL)
			printf("%s\n", env[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}