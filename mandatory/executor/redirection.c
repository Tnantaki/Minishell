/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 09:50:48 by tnantaki          #+#    #+#             */
/*   Updated: 2023/06/24 09:50:49 by tnantaki         ###   ########.fr       */
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
	if (px->outfd != STDOUT_FILENO)
		close(px->outfd);
	if (px->infd != STDIN_FILENO)
		close(px->infd);
	if (!isatty(STDIN_FILENO))
		dup2(px->std_in, STDIN_FILENO);
	if (!isatty(STDOUT_FILENO))
		dup2(px->std_out, STDOUT_FILENO);
	px->infd = STDIN_FILENO;
	px->outfd = STDOUT_FILENO;
	if (px->pipeout)
		px->infd = px->pipefd[0];
	return (true);
}

bool	close_stdio(t_pipe *px)
{
	close(px->std_in);
	close(px->std_out);
	return (true);
}

bool	redirection(t_pipe *px)
{
	if (px->infd != STDIN_FILENO)
	{
		dup2(px->infd, STDIN_FILENO);
		close(px->infd);
	}
	if (px->outfd != STDOUT_FILENO)
	{
		dup2(px->outfd, STDOUT_FILENO);
		close(px->outfd);
	}
	return (true);
}
