/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:25:46 by tnantaki          #+#    #+#             */
/*   Updated: 2023/06/12 13:25:47 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	create_heredoc(char *lim)
{
	char	*tmp;
	int		pipefd[2];

	if (pipe(pipefd) == -1)
		return (printf("Error Heredoc"), -1);
	while (1)
	{
		tmp = readline("> ");
		if (!tmp)
			return (close(pipefd[1]), pipefd[0]);
		if (ft_strcmp(tmp, lim) == 0)
			break ;
		ft_putstr_fd(tmp, pipefd[1]);
		ft_putchar_fd('\n', pipefd[1]);
		free (tmp);
	}
	return (free(tmp), close(pipefd[1]), pipefd[0]);
}

bool	open_heredoc(t_spcmd *spcmd, int nb_cmd)
{
	int	j;
	int	i;

	j = 0;
	while (j < nb_cmd)
	{
		i = 0;
		while (i < spcmd[j].nb.io)
		{
			if (spcmd[j].io[i].rdrt == e_heredoc)
			{
				spcmd[j].io[i].fd = create_heredoc(spcmd[j].io[i].filename); //filename in here_doc is limiter
				if (spcmd[j].io[i].fd == -1)
					return (false);
			}
			else
				spcmd[j].io[i].fd = 0;
			i++;
		}
		j++;
	}
	return (true);
}

static int	open_infile(t_io io, int infd)
{
	if (infd)
		close(infd);
	if (io.rdrt == e_input)
		infd = open(io.filename, O_RDONLY);
	else if (io.rdrt == e_heredoc)
		infd = io.fd;
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
