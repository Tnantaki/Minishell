/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stdio.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:25:51 by tnantaki          #+#    #+#             */
/*   Updated: 2023/06/12 13:25:52 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	save_stdio(t_pipe *px)
{
	px->infd = STDIN_FILENO;
	px->outfd = STDOUT_FILENO;
	px->std_in = dup(STDIN_FILENO);
	px->std_out = dup(STDOUT_FILENO);
	return (true);
}

bool	restore_stdio(t_pipe *px)
{
	if (!isatty(px->infd))
	{
		// dprintf(2, "restore infd :%d\n", px->infd);//debug
		close(px->infd);
		dup2(px->std_in, STDIN_FILENO);
		px->infd = STDIN_FILENO;
	}
	if (!isatty(px->outfd) && px->outfd != -1)
	{
		// dprintf(2, "restore outfd :%d\n", px->outfd);//debug
		close(px->outfd);
		dup2(px->std_out, STDOUT_FILENO);
		px->outfd = STDOUT_FILENO;
	}
	if (px->pipeout)
		px->infd = px->pipefd[0];
	return (true);
}

bool	close_stdio(t_pipe *px)
{
	// dprintf(2, "clo std_in :%d\n", px->std_in);//debug
	// dprintf(2, "clo std_out :%d\n", px->std_out);//debug
	close(px->std_in);
	close(px->std_out);
	return (true);
}

bool	redirection(t_pipe *px)
{
	if (!isatty(px->infd))
	{
		// dprintf(2, "redir infd :%d\n", px->infd);//debug
		dup2(px->infd, STDIN_FILENO);
		close(px->infd);
	}
	if (!isatty(px->outfd))
	{
		// dprintf(2, "redir outfd :%d\n", px->outfd);//debug
		dup2(px->outfd, STDOUT_FILENO);
		close(px->outfd);
	}
	return (true);
}
