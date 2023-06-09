/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:25:42 by tnantaki          #+#    #+#             */
/*   Updated: 2023/06/12 13:25:43 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	create_pid(t_pipe *px, int nb_cmd)
{
	px->pid = ft_calloc(nb_cmd, sizeof(int));
	if (!(px->pid))
		return (perror("Error malloc"), false);
	return (true);
}

bool	create_pipe(t_pipe *px)
{
	if (pipe(px->pipefd) == -1)
	{
		px->pipeout = 0;
		return (perror("Error Pipe"), false);
	}
	px->outfd = px->pipefd[1];
	px->pipeout = 1;
	return (true);
}

bool	wait_process(int *pid, int nb_cmd)
{
	int	i;

	i = 0;
	signal(SIGINT, &sigint_wait_handler);
	while (i < nb_cmd)
	{
		if (pid[i] != 0)
		{
			waitpid(pid[i], &g_status, 0);
			if (WIFEXITED(g_status))
				g_status = WEXITSTATUS(g_status);
			else if (WIFSIGNALED(g_status))
			{
				if (WTERMSIG(g_status) == SIGINT)
					g_status = ES_SIGINT_CHILD;
				else if (WTERMSIG(g_status) == SIGKILL)
					g_status = ES_SIGKILL;
				else if (WTERMSIG(g_status) == SIGSTOP)
					g_status = ES_SIGSTOP;
			}
		}
		i++;
	}
	free(pid);
	return (true);
}

bool	spcmd_execution(t_spcmd spcmd, t_pipe *px, t_msh *msh)
{
	if (spcmd.nb.pipe)
	{
		if (!create_pipe(px))
			return (false);
	}
	else
		px->pipeout = 0;
	if (!spcmd.nb.arg && !spcmd.nb.io)
		return (true);
	if (spcmd.nb.arg && is_built_in(spcmd.arg[0], &px->buin))
		return (buin_execution(spcmd, px, msh));
	if (!cmd_execution(spcmd, px))
		return (false);
	return (true);
}

bool	executor(t_spcmd *spcmd, t_msh *msh)
{
	int		nb_cmd;
	t_pipe	px;

	nb_cmd = msh->nb_cmd;
	if (!create_pid(&px, nb_cmd))
		return (false);
	if (!open_heredoc(spcmd, nb_cmd))
		return (false);
	save_stdio(&px);
	px.i = 0;
	while (px.i < nb_cmd)
	{
		spcmd_execution(spcmd[px.i], &px, msh);
		restore_stdio(&px);
		px.i++;
	}
	close_stdio(&px);
	wait_process(px.pid, nb_cmd);
	return (true);
}
