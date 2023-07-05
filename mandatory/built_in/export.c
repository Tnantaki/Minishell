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

static void	sort_export(char **tmp_env, size_t amv)
{
	size_t	i;
	char	*tmp;

	i = 0;
	while (i < amv && tmp_env[i + 1])
	{
		if (ft_strcmp(tmp_env[i], tmp_env[i + 1]) > 0)
		{
			tmp = NULL;
			tmp = tmp_env[i];
			tmp_env[i] = tmp_env[i + 1];
			tmp_env[i + 1] = tmp;
		}
		i++;
	}
}

static int	display_sorted_export(char **env)
{
	size_t	j;
	size_t	amv;
	char	**tmp_env;

	tmp_env = ft_2dstrdup(env);
	if (!tmp_env)
		return (EXIT_FAILURE);
	amv = ft_2dstrlen(tmp_env);
	j = 0;
	while (j < amv)
	{
		sort_export(tmp_env, amv);
		j++;
	}
	j = 0;
	while (tmp_env[j])
	{
		ft_putstr_fd("declare -x ", STDOUT_FILENO);
		ft_putstr_fd(tmp_env[j++], STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
	}
	return (ft_free2dstr(tmp_env), EXIT_SUCCESS);
}

// Create_var
// will allocate new 2D string + 2 for new_var and NULL
// assign all env variables to tmp_env
// insert the new variable(s)
static int	create_var(char *new_var)
{
	int		i;
	char	**env;
	char	**tmp_env;

	env = get_env();
	tmp_env = (char **)malloc(sizeof(char *) * (ft_2dstrlen(env) + 2));
	if (!tmp_env)
		return (EXIT_FAILURE);
	i = 0;
	while (env[i])
	{
		tmp_env[i] = env[i];
		i++;
	}
	tmp_env[i++] = ft_strdup(new_var);
	tmp_env[i] = NULL;
	set_env(tmp_env);
	free(env);
	return (EXIT_SUCCESS);
}

int	ft_export(char **arg)
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
			continue ;
		var_len = ft_var_len(arg[i]);
		env = search_env_var(arg[i], var_len);
		if (env)
		{
			if (arg[i][var_len] == '=')
				del_env(env, 0);
			else
				continue ;
		}
		status = create_var(arg[i]);
	}
	return (status);
}
