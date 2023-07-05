/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truangsi <truangsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:16:04 by truangsi          #+#    #+#             */
/*   Updated: 2023/06/16 17:13:44 by truangsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	del_env(char **env, int j)
{
	int	i;

	free(env[j]);
	env[j] = NULL;
	i = j;
	while (env[i + 1])
	{
		env[i] = env[i + 1];
		i++;
	}
	env[i] = NULL;
}

int	ft_unset(char **arg)
{
	int		i;
	int		status;
	char	**env;

	status = 0;
	i = 0;
	while (arg[++i])
	{
		if (!check_valid_var(arg[i], &status, "unset: `"))
			continue ;
		env = search_env_var(arg[i], ft_strlen(arg[i]));
		if (env)
			del_env(env, 0);
	}
	return (status);
}
