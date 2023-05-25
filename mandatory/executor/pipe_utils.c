#include "minishell.h"

bool	findpath(t_pipe *px)
{
	char	*tmp;
	char	**path;
	int		i;

	tmp = getenv("PATH");
	if (!tmp)
		return (perror("Can't Find Path"), false);
	path = ft_split(tmp, ':');
	if (!path)
		return (perror("Error malloc"), false);
	i = 0;
	while (path[i])
	{
		path[i] = ft_strjoinfree(path[i], "/");
		if (!path)
			return (ft_free2d_str(path), perror("Error malloc"), false);
		i++;
	}
	px->path = path;
	return (true);
}

bool	create_pipe(t_pipe *px, int nb_cmd)
{
	int	i;

	i = 0;
	px->pipefd = malloc(sizeof(int) * (px->nb_pipe * 2));
	px->pid = malloc(sizeof(int) * (nb_cmd));
	if (!(px->pipefd) || !(px->pid))
		return (perror("Error malloc"), false);
	while (i < px->nb_pipe)
	{
		if (pipe(px->pipefd + (i * 2)) == -1)
			return (perror("Error Pipe"), false);
		i++;
	}
	return (true);
}

bool	close_pipe(t_pipe *px)
{
	int	i;
	int	nb_pipefd;

	i = 0;
	nb_pipefd = px->nb_pipe * 2;
	while (i < nb_pipefd)
	{
		close(px->pipefd[i]);
		i++;
	}
	free (px->pipefd);
	return (true);
}
