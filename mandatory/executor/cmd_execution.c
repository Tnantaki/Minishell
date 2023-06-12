#include "minishell.h"

static bool	findpath(char ***r_path)
{
	char	**path;
	char	*tmp;
	int		i;

	tmp = getenv("PATH");
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

static bool	find_cmd(char **cmd, char *arg)
{
	char	**path;
	int		i;

	i = 0;
	if (access(arg, F_OK) == 0)
		return (*cmd = ft_strdup(arg), true);
	if (arg[0] == '/' && access(arg, F_OK) != 0)
		return (perror(arg), false);
	if (!findpath(&path))
		return (false);
	while (path[i])
	{
		*cmd = ft_strjoin(path[i], arg);
		if (access(*cmd, F_OK) == 0)
			return (ft_free2dstr(path), true);
		free (*cmd);
		i++;
	}
	ft_free2dstr(path);
	arg = ft_strjoin(arg, ": command not found\n");
	ft_putstr_fd(arg, STDERR_FILENO);
	g_status = 127;
	return (free(arg), false);
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

