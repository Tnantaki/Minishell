/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prachman <prachman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:37:04 by prachman          #+#    #+#             */
/*   Updated: 2023/06/21 19:20:58 by prachman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	update_pwd(char *pwd)
{
	int		i;
	char	*cwd;
	char	**env;
	char	*tmp;

	env = get_env();
	cwd = getcwd(NULL, 0);
	if (!env || !cwd)
		return (false);
	i = 0;
	while (env[i]) // update PWD
	{
		if (ft_strncmp(env[i], pwd, ft_strlen(pwd)) == 0) //minus equal sign
		{
			tmp = env[i];
			env[i] = ft_strjoin(pwd, cwd);
			return (free(tmp), free(cwd), true);
		}
		i++;
	}
	return (free(cwd), false);
}

static bool	ft_isnotdir(char *path)
{
	struct stat	info;

	if (stat(path, &info) != 0)
	{
		ft_prterrf("cd: ", path, ": No such file or directory\n");
		return (false);
	}
	if (!S_ISDIR(info.st_mode))
	{
		ft_prterrf("cd: ", path, ": Not a directory\n");
		return (false);
	}
	if (!(info.st_mode & S_IXUSR))
	{
		ft_prterrf("cd: ", path, ": Permission denied\n");
		return (false);
	}
	return (true);
}

int	ft_cd(char **arg)
{
	char		*path;

	if (ft_2dstrlen(arg) > 2)
		return (ft_prterr("cd: too many arguments\n"), EXIT_FAILURE);
	if (!arg[1])
		path = get_env_value("HOME");
	else
		path = ft_strdup(arg[1]);
	if (!ft_isnotdir(path))
		return (free(path), EXIT_FAILURE);
	update_pwd("OLDPWD=");
	if (chdir(path) < 0)
		return (perror("error"), free(path), EXIT_FAILURE);
	update_pwd("PWD=");
	free(path);
	return (EXIT_SUCCESS);
}
