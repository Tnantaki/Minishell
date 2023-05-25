#include "minishell.h"

int	*ft_create_pipe(int	nb_pipe, int nb_cmd)
{
	int	i;
	int	*pipefd;
	int	*pid;

	i = 0;
	pipefd = malloc(sizeof(int) * (nb_pipe * 2));
	pid = malloc(sizeof(int) * (nb_cmd));
	if (!(pipefd) || !(pid))
	{
		perror("malloc error");
		exit(1);
	}	
	// {
	// 	ft_double_free(px->path);
	// 	close(px->fd_in);
	// 	if (px->here_doc)
	// 		unlink(HERE_DOC_PATH);
	// 	ft_prterr(PIPE_ERR, NULL, errno);
	// }
	while (i < nb_pipe)
	{
		if (pipe(pipefd + (i * 2)) == -1)
		{
			perror("pipe error");
			exit (1);
			// ft_double_free(px->path);
			// close(px->fd_in);
			// if (px->here_doc)
			// 	unlink(HERE_DOC_PATH);
			// free(px->fd_pipe);
			// free(px->pid);
			// ft_prterr(PIPE_ERR, NULL, errno);
		}
		px->i++;
	}
	return (pipefd);
}

void	ft_close_pipe(t_pipe *px)
{
	int	i;
	int	fd_pipe_nb;

	i = 0;
	fd_pipe_nb = px->pipe_nb * 2;
	while (i < fd_pipe_nb)
	{
		close(px->fd_pipe[i]);
		i++;
	}
	free (px->fd_pipe);
}
