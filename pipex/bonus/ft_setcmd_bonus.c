#include "minishell.h"

void	ft_first_cmd(int *pipefd)
{
	int	infd;
	int	fd_read;
	int	fd_write;


	infd = ft_open_infile(io);
	if (infd == -1)
		exit (1);
	fd_read = infd;
	fd_write = pipefd[1];
	dup2(fd_read, STDIN_FILENO);
	dup2(fd_write, STDOUT_FILENO);
	close(infd);
}

void	ft_mid_cmd(int *pipefd, int i)
{
	int	fd_read;
	int	fd_write;

	fd_read = pipefd[(i - 1) * 2];
	fd_write = pipefd[(i * 2) + 1];
	dup2(fd_read, STDIN_FILENO);
	dup2(fd_write, STDOUT_FILENO);
}

void	ft_last_cmd(int *pipefd, int i)
{
	int	outfd;
	int	fd_read;
	int	fd_write;

	outfd = ft_open_outfile(io);
	if (outfd == -1)
		exit (1);
	fd_read = fd_pipe[(i - 1) * 2];
	fd_write = outfd;
	dup2(fd_read, STDIN_FILENO);
	dup2(fd_write, STDOUT_FILENO);
	close(outfd);
}
