/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_execution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:25:37 by tnantaki          #+#    #+#             */
/*   Updated: 2023/06/12 13:25:39 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	findpath(char ***r_path)
{
	char	**path;
	char	*tmp;
	int		i;

	tmp = get_env_value("PATH");
	if (!tmp)
		return (true);
	path = ft_split(tmp, ':');
	if (!path)
		return (perror("Error malloc"), false);
	i = 0;
	while (path[i])
	{
		path[i] = ft_strjoinfree(path[i], "/");
		if (!path)
			return (ft_free2dstr(path), perror("Error malloc"), false);
		i++;
	}
	*r_path = path;
	return (true);
}

static void	err_cmd_exec(int errnum, char *arg, char **path)
{
	if (errnum == 1)
		arg = ft_strjoin(arg, ": is directory\n");
	else if (errnum == 2 && !path)
		arg = ft_strjoin(arg, ": No such file or directory\n");
	else if (errnum == 2)
		arg = ft_strjoin(arg, ": command not found\n");
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_free2dstr(path);
	free(arg);
	if (errnum == 1)
		g_status = 126;
	else
		g_status = 127;
}


static bool	find_cmd(char **cmd, char *arg)
{
	int		i;
	char	**path;

	i = 0;
	path = NULL;
	if (ft_strcmp(arg, "/") == 0)
		return (err_cmd_exec(1, arg, path), false);
	if (access(arg, F_OK) == 0)
		return (*cmd = ft_strdup(arg), true);
	if (arg[0] == '/' && access(arg, F_OK) != 0)
		return (perror(arg), false);
	if (!findpath(&path))
		return (false);
	while (path && path[i])
	{
		*cmd = ft_strjoin(path[i], arg);
		if (access(*cmd, F_OK) == 0)
			return (ft_free2dstr(path), true);
		free (*cmd);
		i++;
	}
	return (err_cmd_exec(2, arg, path), false);
}

bool	cmd_execution(char **arg, t_pipe *px)
{
	char	*cmd;

	px->pid[px->i] = fork();
	if (px->pid[px->i] == -1)
		return (perror("Fork Fail"), false);
	if (px->pid[px->i] == 0)
	{
		free(px->pid);
		if (!find_cmd(&cmd, arg[0]))
			exit(g_status);
		if (execve(cmd, arg, get_env()) == -1)
			exit(errno);
	}
	return (true);
}
