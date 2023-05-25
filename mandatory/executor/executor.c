#include "minishell.h"

bool	join_path(t_spcmd *spcmd, char **path)
{
	int		i;

	i = 0;
	if (access(spcmd->arg[0], F_OK) == 0)
		return (spcmd->cmd = ft_strdup(spcmd->arg[0]), true);
	if (spcmd->arg[0][0] == '/' && access(spcmd->arg[0], F_OK) != 0)
		return (perror(spcmd->arg[0]), false);
	while (path[i])
	{
		spcmd->cmd = ft_strjoin(path[i], spcmd->arg[0]);
		if (access(spcmd->cmd, F_OK) == 0)
			return (true);
		free (spcmd->cmd);
		i++;
	}
	// ft_double_free(cmd);
	// ft_double_free(path);
	// ft_prterr(COM_ERR, pathname, 127);
	return (true);
}

bool	redirection(t_spcmd spcmd, t_pipe px, int i)
{
	if (spcmd.nb.in)
		dup2(px.infd, STDIN_FILENO);
	else if (spcmd.nb.pipe)
		dup2(px.pipefd[(i - 1) * 2], STDIN_FILENO);
	if (spcmd.nb.out)
		dup2(px.outfd, STDOUT_FILENO);
	else if (i < px.nb_pipe)
		dup2(px.pipefd[(i * 2) + 1], STDOUT_FILENO);
	return (true);
}

bool	fork_child(t_spcmd spcmd, t_pipe *px)
{
	px->pid[px->i] = fork();
	if (px->pid[px->i] == -1)
		return (perror("Fork Fail"), false);
	if (px->pid[px->i] == 0)
	{
		free(px->pid);
		// px->cmd_i = px->i + 2 + px->here_doc;
		if (spcmd.nb.in)
			open_infile(spcmd.in, spcmd.nb.in, &(px->infd));
		if (spcmd.nb.out)
			open_outfile(spcmd.out, spcmd.nb.out, &(px->outfd));
		redirection(spcmd, *px, px->i);
		close_pipe(px);
		if (spcmd.nb.arg)
			join_path(&spcmd, px->path);
		if (execve(spcmd.cmd, spcmd.arg, px->env) == -1)
			exit(errno);
	}
	return (true);
}

bool	executor(t_spcmd *spcmd, int nb_cmd, int nb_pipe)
{
	t_pipe	px;

	px.nb_pipe = nb_pipe;
	px.env = get_env();
	if (!findpath(&px))
		return (false);
	if (!create_pipe(&px, nb_cmd))
		return (false);
	px.i = 0;
	printf("nb_cmd:%d\n", nb_cmd);
	while (px.i < nb_cmd)
	{
		if (!fork_child(spcmd[px.i], &px))
			return (false);
		px.i++;
	}
	printf("px.i:%d\n", px.i);
	px.i = 0;
	close_pipe(&px);
	while (px.i < nb_cmd)
		waitpid(px.pid[px.i++], &px.status, 0);
	free(px.pid);
	if (open(HEREDOC, O_RDONLY) != -1)
		unlink(HEREDOC);
	// return (WEXITSTATUS(px.status));
	return (true);
}