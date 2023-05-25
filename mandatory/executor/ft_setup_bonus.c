#include "minishell.h"

static void	ft_create_here_doc(char *lim)
{
	char	*tmp;
	int		fd;
	int		len;

	fd = open(HEREDOC, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		ft_prterr(HERE_DOC, HEREDOC, errno);
	len = ft_strlen(lim);
	while (1)
	{
		ft_putstr_fd("heredoc> ", STDOUT_FILENO);
		tmp = readline(STDIN_FILENO);
		if (!tmp)
			ft_gnl_err(px);
		if (ft_strncmp(lim, tmp, len) == 0 && tmp[len] == '\n')
			break ;
		ft_putstr_fd(tmp, fd);
		free (tmp);
	}
	free (tmp);
	close(fd);
}

int	ft_open_infile(t_io *io)
{
	int	fd;

	while (io)
	{
		if (io->rdrt == heredoc)
		{
			ft_create_here_doc(io.filename);//filename in here_doc is limiter
			io->filename = HEREDOC;
		}
		fd = open(io->filename, O_RDONLY);
		if (fd == -1)
		{
			perror(io->filename);
			return (-1);
		}
		io++;
	}
	return (fd);
}

int	ft_open_outfile(t_io *io)
{
	int	fd;

	while (io)
	{
		if (io.rdrt == append)
			fd = open(io->filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
		else
			fd = open(io->filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
		{
			perror(io->filename);
			return (-1);
		}
		io++;
	}
	return (fd);
}
