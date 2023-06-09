#include "minishell.h"

static bool	create_heredoc(char *lim)
{
	char	*tmp;
	int		fd;
	int		len;

	fd = open(HEREDOC, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (perror(HEREDOC), false);
	len = ft_strlen(lim);
	while (1)
	{
		ft_putstr_fd("heredoc> ", STDOUT_FILENO);
		tmp = readline(STDIN_FILENO);
		if (!tmp)
			return (perror("Error malloc"), false);
		if (ft_strncmp(lim, tmp, len) == 0 && tmp[len] == '\n')
			break ;
		ft_putstr_fd(tmp, fd);
		free (tmp);
	}
	free (tmp);
	close(fd);
	return (true);
}

static int	open_infile(t_io io,int infd)
{
	if (infd)
		close(infd);
	if (io.rdrt == e_input)
		infd = open(io.filename, O_RDONLY);
	else if (io.rdrt == e_heredoc)
	{
		create_heredoc(io.filename);//filename in here_doc is limiter
		infd = open(HEREDOC, O_RDONLY);
	}
	return (infd);
}

static int	open_outfile(t_io io, int outfd)
{
	if (outfd)
		close(outfd);
	if (io.rdrt == e_output)
		outfd = open(io.filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (io.rdrt == e_append)
		outfd = open(io.filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
	return (outfd);
}

bool	redirection(t_io *io, int nb_io, t_pipe *px)
{
	int	i;

	i = 0;
	while (i < nb_io)
	{
		if (io[i].rdrt == e_input || io[i].rdrt == e_heredoc)
			px->infd = open_infile(io[i], px->infd);
		else if (io[i].rdrt == e_output || io[i].rdrt == e_append)
			px->outfd = open_outfile(io[i], px->outfd);
		if (px->infd == -1 || px->outfd == -1)
			return (perror(io[i].filename), false);
		i++;
	}
	if (px->infd)
	{
		dup2(px->infd, STDIN_FILENO);
		close(px->infd);
	}
	if (px->outfd)
	{
		dup2(px->outfd, STDOUT_FILENO);
		close(px->outfd);
	}
	return (true);
}
