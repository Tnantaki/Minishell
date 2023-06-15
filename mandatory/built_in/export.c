/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truangsi <truangsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:45:33 by prachman          #+#    #+#             */
/*   Updated: 2023/06/15 16:34:09 by truangsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void create_var(char **tmp_env, char **env, char **arg, int arg_size)
{
	int	i;
	int	j;

	i = 0;
	while (env[i])
	{
		tmp_env[i] = env[i];
		i++;
	}
	j = 1;
	while (j < arg_size)
	{
		tmp_env[i] = ft_strdup(arg[j]);
		i++;
		j++;
	}
	tmp_env[i] = NULL;
	set_env(tmp_env);
	i = 0;
	// while (tmp_env[i])
	// {
	// 	printf("here:%s\n", tmp_env[i++]);
	// }
}

int ft_export(char **arg)
{
	char	**env;
	char	**tmp_env;
	char	*tmp;
	int		arg_size;
	int		i;
	int		j;

	env = get_env();
	arg_size = ft_2dstrlen(arg);
	if (arg_size > 1) // store new vars if any
	{
		tmp_env = (char **)malloc(sizeof(char *) * (ft_2dstrlen(env) + arg_size));
		if (!tmp_env)
			return (EXIT_FAILURE);
		create_var(tmp_env, env, arg, arg_size);
		return (EXIT_SUCCESS); //done creating new var
	}
	else //copy the current env
		tmp_env = ft_2dstrdup(env);
	i = 0;
	while ((size_t) i < ft_2dstrlen(tmp_env)) // sort vars
	{
		j = 0;
		while ((size_t) j < ft_2dstrlen(tmp_env) && tmp_env[j + 1])
		{
			if (ft_strcmp(tmp_env[j], tmp_env[j + 1]) > 0)
			{
				tmp = tmp_env[j];
				tmp_env[j] = tmp_env[j + 1];
				tmp_env[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (tmp_env[i])
		printf("%s\n",tmp_env[i++]);
	// free(tmp_env);
	return (EXIT_SUCCESS);
}