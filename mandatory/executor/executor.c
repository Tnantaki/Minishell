#include "minishell.h"

bool	create_pid(t_pipe *px, int nb_cmd)
{
	int	i;

	px->pid = malloc(sizeof(int) * (nb_cmd));
	if (!(px->pid))
		return (perror("Error malloc"), false);
	i = 0;
	while (i < nb_cmd)
		px->pid[i++] = 0;
	return (true);
}

bool	create_pipe(t_pipe *px)
{
	if (pipe(px->pipefd) == -1)
		return (perror("Error Pipe"), false);
	px->outfd = px->pipefd[1];
	return (true);
}

bool	wait_process(int *pid, int nb_cmd, int *status)
{
	int	i;

	i = 0;
	while (i < nb_cmd)
	{
		if (pid[i] != 0)
			waitpid(pid[i], status, 0);
		i++;
	}
	free(pid);
	return (true);
}

bool	spcmd_execution(t_spcmd spcmd, t_pipe *px)
{
	if (spcmd.nb.pipe && !create_pipe(px))
		return (false);
	if (!redirection(spcmd.io, spcmd.nb.io ,px))
		return (false);
	if (is_built_in(spcmd.arg[0], &px->buin))
		return (buin_execution(px->buin, spcmd.arg), true);
	if (!cmd_execution(spcmd.arg, px))
		return (false);
	return (true);
}

bool	executor(t_spcmd *spcmd, int nb_cmd)
{
	t_pipe	px;

	if (!create_pid(&px, nb_cmd))
		return (false);
	save_stdio(&px);
	px.i = 0;
	while (px.i < nb_cmd)
	{
		px.infd = 0;
		px.outfd = 0;
		if (px.i != 0 && spcmd[px.i - 1].nb.pipe)
			px.infd = px.pipefd[0];
		spcmd_execution(spcmd[px.i], &px);
		restore_stdio(&px);
		px.i++;
	}
	close_stdio(&px);
	wait_process(px.pid, nb_cmd, &g_status);
	if (open(HEREDOC, O_RDONLY) != -1)
		unlink(HEREDOC);
	// return (WEXITSTATUS(px.status));
	return (true);
}