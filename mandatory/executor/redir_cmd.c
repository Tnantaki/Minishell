#include "minishell.h"

void	first_cmd(t_spcmd spcmd, t_pipe *px)
{
	open_infile(spcmd.in, spcmd.nb.in);
	if (px->fd_in == -1)
	{
		ft_close_pipe(px);
		ft_double_free(px->path);
		exit (2);
	}
	px->fd_read = px->fd_in;
	px->fd_write = px->fd_pipe[1];
	dup2(px->fd_read, STDIN_FILENO);
	dup2(px->fd_write, STDOUT_FILENO);
	close(px->fd_in);
}

void	ft_mid_cmd(t_pipe *px)
{
	px->fd_read = px->fd_pipe[(px->i - 1) * 2];
	px->fd_write = px->fd_pipe[(px->i * 2) + 1];
	dup2(px->fd_read, STDIN_FILENO);
	dup2(px->fd_write, STDOUT_FILENO);
}

void	ft_last_cmd(t_pipe *px, char **av)
{
	int	out_i;

	out_i = px->i + 3 + px->here_doc;
	if (px->here_doc)
		px->fd_out = open(av[out_i], O_WRONLY | O_CREAT | O_APPEND, 0777);
	else
		px->fd_out = open(av[out_i], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (px->fd_out == -1)
	{
		close(px->fd_in);
		ft_close_pipe(px);
		ft_double_free(px->path);
		ft_prterr(NO_OUTFILE, av[out_i], 1);
	}
	px->fd_read = px->fd_pipe[(px->i - 1) * 2];
	px->fd_write = px->fd_out;
	dup2(px->fd_read, STDIN_FILENO);
	dup2(px->fd_write, STDOUT_FILENO);
	close(px->fd_out);
}
