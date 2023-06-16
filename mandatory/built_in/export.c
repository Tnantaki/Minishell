/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truangsi <truangsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:45:33 by prachman          #+#    #+#             */
/*   Updated: 2023/06/16 17:58:32 by truangsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**replace_exist_var(char **env, char **arg)
{
	int		i;
	int		j;
	int		lst_env;
	char	**var;

	var = NULL;
	lst_env = ft_2dstrlen(env) - 1;
	i = 1;
	while (arg[i])
	{
		var = ft_split(arg[i], '='); //get the variable name
		j = 0;
		while (env[j])
		{
			if (ft_strncmp(var[0], env[j], ft_strlen(var[0])) == 0) // founded the name
			{
				del_env(env, lst_env); //delete the last env and rearrange the position
				env[j] = ft_strdup(arg[i]); //add new env
			}
			j++;
		}
		i++;
	}
	ft_free2dstr(var);
	return (env);
}

static void create_var(char **tmp_env, char **env, char **arg, int arg_size)
{
	int	i;
	int	j;

	i = 0;
	while (env[i]) // assign all env variable to tmp_env
	{
		tmp_env[i] = env[i];
		i++;
	}
	j = 1;
	while (j < arg_size) // insert the new variable at the end of the array
	{
		tmp_env[i] = ft_strdup(arg[j]);
		i++;
		j++;
	}
	tmp_env[i] = NULL; //done creating
	replace_exist_var(tmp_env, arg);
	set_env(tmp_env);
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
	// ft_free2dstr(tmp_env);
	return (EXIT_SUCCESS);
}