/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truangsi <truangsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:45:33 by prachman          #+#    #+#             */
/*   Updated: 2023/06/18 12:59:11 by truangsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	del_exp(char **env, int	j)
{
	int	i;

	free(env[j]);
	env[j] = NULL;
	i = j;
	while (env[i + 1]) //make new order
	{
		env[i] = env[i + 1];
		// printf("here:%s\n", env[i]);
		i++;
	}
	// if (!env[i])
	env[i] = NULL;
}

// char	**replace_exist_var(char **env)
// {
// 	int	i;
// 	int	j;
// 	char	**var;

// 	var = NULL;
// 	i = 0;
// 	while (env[i])
// 	{
// 		var = ft_split(env[i], '='); //get the variable name
// 		j = 0;
// 		while (env[j])
// 		{
// 			if (ft_strncmp(var[0], env[j], ft_strlen(var[0])) == 0
// 				&& env[i][ft_strlen(var[0])] == '=')
// 			{
// 				// printf("in loop:%s\n", var[0]);
// 				del_exp(env, j); //delete the last env and rearrange the position
// 				// env[j] = ft_strdup(arg[i]); //add new env
// 				break ;
// 			}
// 			j++;
// 		}
// 		// ft_free2dstr(venv;
// 		i++;
// 	}
// 	return (env);
// }

// void	replace_exist_env(char **env, char **arg)
void	replace_exist_env(char **env)
{
	int i;
	int	j;
	int	cnt;

	i = 0;
	while (env[i])
	{
		j = 0;
		cnt = 0;
		while (env[j])
		{
			if (ft_strcmp(env[i], env[j]) == 0) // find var with the same name and value
				cnt++;
			if (cnt > 1)
			{
				// printf("delete:%s\n", env[j]);
				del_exp(env, j);
			}
			j++;
		}
		i++;
	}
}

void	replace_exist_var(char **env, char **arg)
{
	int		i;
	int		j;
	char	**var;

	var = NULL;
	i = 1;
	while (arg[i])
	{
		var = ft_split(arg[i], '='); //get the variable name
		j = 0;
		// printf("arg:%s\n", arg[i]);
		// printf("var:%s\n", var[0]);
		while (env[j])
		{
			if (ft_strcmp(env[j], arg[i]) == 0)
				break ;
			//founded the same name
			if (ft_strncmp(var[0], env[j], ft_strlen(var[0])) == 0
				&& arg[i][ft_strlen(var[0])] == '=')
			{
				// printf("in loop:%s\n", var[0]);
				// printf("first loop:%s\n", env[j]);
				del_exp(env, j); //delete the last env and rearrange the position
				// env[j] = ft_strdup(arg[i]); //add new env
				// ft_free2dstr(var);
				break ;
			}
			j++;
		}
		ft_free2dstr(var);
		i++;
	}
	// ft_free2dstr(var);
	// return (env);
}

static void create_var(char **tmp_env, char **env, char **arg, int arg_size)
{
	int	i;
	int	j;

	i = 0;
	while (env[i]) // assign all env variables to tmp_env
	{
		tmp_env[i] = env[i];
		i++;
	}
	j = 1;
	while (j < arg_size) // insert the new variable(s) at the end of the array
	{
		tmp_env[i] = ft_strdup(arg[j]);
		i++;
		j++;
	}
	tmp_env[i] = NULL; //done creating
	// i = 0;
	// while (tmp_env[i])
	// {
	// 	printf("here:%s\n", tmp_env[i++]);
	// }
	// replace_exist_var(tmp_env, arg);
	replace_exist_var(tmp_env, arg);
	replace_exist_env(tmp_env);
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