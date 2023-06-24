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
	px->infd = 0;
	px->outfd = 0;
	px->std_in = dup(STDIN_FILENO);
	px->std_out = dup(STDOUT_FILENO);
	return (true);
}

bool	restore_stdio(t_pipe *px)
{
	close(px->outfd);
	if (!isatty(STDIN_FILENO))
		dup2(px->std_in, STDIN_FILENO);
	if (!isatty(STDOUT_FILENO))
		dup2(px->std_out, STDOUT_FILENO);
	px->infd = 0;
	px->outfd = 0;
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
