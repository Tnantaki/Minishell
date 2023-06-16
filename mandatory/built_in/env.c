/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truangsi <truangsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:16:04 by truangsi          #+#    #+#             */
/*   Updated: 2023/06/16 17:13:44 by truangsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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