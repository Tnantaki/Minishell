/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truangsi <truangsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:45:33 by prachman          #+#    #+#             */
/*   Updated: 2023/06/18 17:02:49 by truangsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_push_swap(char **tmp_env, int i)
{
	char	*tmp;

	tmp = NULL;
	tmp = tmp_env[i];
	tmp_env[i] = tmp_env[i + 1];
	tmp_env[i + 1] = tmp;
}

static int	display_sorted_export(char **env)
{
	size_t	i;
	size_t	j;
	size_t	amv; //amount of variable in env
	char	**tmp_env;

	tmp_env = ft_2dstrdup(env);
	if (!tmp_env)
		return (EXIT_FAILURE);
	amv = ft_2dstrlen(tmp_env);
	j = 0;
	while (j < amv) // sort vars
	{
		i = 0;
		while (i < amv && tmp_env[i + 1])
		{
			if (ft_strcmp(tmp_env[i], tmp_env[i + 1]) > 0)
				ft_push_swap(tmp_env, i);
			i++;
		}
		j++;
	}
	j = 0;
	while (tmp_env[j])
		printf("declare -x %s\n",tmp_env[j++]);
	return (ft_free2dstr(tmp_env), EXIT_SUCCESS);
}

// void	replace_exist_env(char **env)
// {
// 	int i;
// 	int	j;
// 	int	cnt;

// 	i = 0;
// 	while (env[i])
// 	{
// 		j = 0;
// 		cnt = 0;
// 		while (env[j])
// 		{
// 			if (ft_strcmp(env[i], env[j]) == 0) // find var with the same name and value
// 				cnt++;
// 			if (cnt > 1)
// 				del_env(env, j);
// 			j++;
// 		}
// 		i++;
// 	}
// }

// void	replace_exist_var(char **env, char **arg)
// {
// 	int		i;
// 	int		j;
// 	char	**var;

// 	var = NULL;
// 	i = 1;
// 	while (arg[i])
// 	{
// 		var = ft_split(arg[i], '='); //get the variable name
// 		j = 0;
// 		while (env[j])
// 		{
// 			if (ft_strcmp(env[j], arg[i]) == 0)
// 				break ;
// 			//founded the same name
// 			if (ft_strncmp(var[0], env[j], ft_strlen(var[0])) == 0
// 				&& env[j][ft_strlen(var[0])] == '=')
// 			{
// 				del_env(env, j); //delete the last env and rearrange the position
// 				break ;
// 			}
// 			j++;
// 		}
// 		ft_free2dstr(var);
// 		i++;
// 	}
// }

// static void create_var(char **tmp_env, char **env, char **arg, int arg_size)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (env[i]) // assign all env variables to tmp_env
// 	{
// 		tmp_env[i] = env[i];
// 		i++;
// 	}
// 	j = 1;
// 	while (j < arg_size) // insert the new variable(s) at the end of the array
// 	{
// 		if (!ft_isalpha(arg[j][0])) // skip invalid arg
// 		{
// 			j++;
// 			continue ;
// 		}
// 		tmp_env[i] = ft_strdup(arg[j]);
// 		i++;
// 		j++;
// 	}
// 	tmp_env[i] = NULL; //done creating
// 	replace_exist_var(tmp_env, arg);
// 	replace_exist_env(tmp_env);
// 	set_env(tmp_env);
// }

// int ft_export(char **arg)
// {
// 	char	**env;
// 	char	**tmp_env;
// 	char	*tmp;
// 	int		arg_size;
// 	int		i;
// 	int		j;

// 	i = 1;
// 	while (arg[i])
// 	{
// 		if (!ft_isalpha(arg[i][0]))
// 		{
// 			ft_prterrf("export: `", arg[i], "': not a valid identifier\n");
// 			i++;
// 			continue ;
// 		}
// 		i++;
// 	}
// 	env = get_env();
// 	arg_size = ft_2dstrlen(arg);
// 	if (arg_size > 1) // store new vars if any
// 	{
// 		tmp_env = (char **)malloc(sizeof(char *) * (ft_2dstrlen(env) + arg_size));
// 		if (!tmp_env)
// 			return (EXIT_FAILURE);
// 		create_var(tmp_env, env, arg, arg_size);
// 		return (EXIT_SUCCESS); //done creating new var
// 	}
// 	else //copy the current env
// 		tmp_env = ft_2dstrdup(env);
// 	i = 0;
// 	while ((size_t) i < ft_2dstrlen(tmp_env)) // sort vars
// 	{
// 		j = 0;
// 		while ((size_t) j < ft_2dstrlen(tmp_env) && tmp_env[j + 1])
// 		{
// 			if (ft_strcmp(tmp_env[j], tmp_env[j + 1]) > 0)
// 			{
// 				tmp = tmp_env[j];
// 				tmp_env[j] = tmp_env[j + 1];
// 				tmp_env[j + 1] = tmp;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	i = 0;
// 	while (tmp_env[i])
// 		printf("declare -x %s\n",tmp_env[i++]);
// 	return (EXIT_SUCCESS);
// }

static int create_var(char *new_var)
{
	int		i;
	char	**env;
	char	**tmp_env;

	env = get_env();
	tmp_env = (char **)malloc(sizeof(char *) * (ft_2dstrlen(env) + 2)); //1 more for new_var and 1 more for NULL
	if (!tmp_env)
		return (EXIT_FAILURE);
	i = 0;
	while (env[i]) // assign all env variables to tmp_env
	{
		tmp_env[i] = env[i];
		i++;
	}
	tmp_env[i++] = ft_strdup(new_var); //insert the new variable(s) at the end of the array
	tmp_env[i] = NULL; //done creating
	set_env(tmp_env);
	free(env);
	return (EXIT_SUCCESS);
}


int ft_export(char **arg)
{
	int		i;
	int		var_len;
	int		status;
	char	**env;

	status = 0;
	if (!arg[1])
		return (display_sorted_export(get_env()));
	i = 0;
	while (arg[++i])
	{
		if (!check_valid_var(arg[i], &status, "export: `"))
			continue;
		var_len = ft_var_len(arg[i]);
		env = search_env_var(arg[i], var_len);
		if (env)
		{
			if (arg[i][var_len] == '=')
				del_env(env, 0);
			else
				continue;
		}
		status = create_var(arg[i]);
	}
	return (status);
}
