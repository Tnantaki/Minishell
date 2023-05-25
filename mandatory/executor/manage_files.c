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

bool	open_infile(t_io *in, int nb_in, int *infd)
{
	int	fd;
	int	i;

	i = 0;
	while (i < nb_in)
	{
		if (in[i].rdrt == heredoc)
		{
			create_heredoc(in[i].filename);//filename in here_doc is limiter
			in[i].filename = HEREDOC;
		}
		fd = open(in[i].filename, O_RDONLY);
		if (fd == -1)
			return (perror(in[i].filename), false);
		i++;
	}
	*infd = fd;
	return (true);
}

bool	open_outfile(t_io *out, int nb_out, int *outfd)
{
	int	fd;
	int	i;

	i = 0;
	while (i < nb_out)
	{
		if (out[i].rdrt == append)
			fd = open(out[i].filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
		else
			fd = open(out[i].filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
			return (perror(out[i].filename), false);
		i++;
	}
	*outfd = fd;
	return (fd);
}
