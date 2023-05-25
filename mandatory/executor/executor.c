#include "minishell.h"

char	**ft_findpath(void)
{
	char	*tmp;
	char	**path;
	int		i;

	tmp = getenv("PATH");
	if (!tmp)
		return (NULL);
	path = ft_split(tmp, ':');
	if (!path)
		return (NULL);
	i = 0;
	while (path[i])
	{
		path[i] = ft_strjoinfree(path[i], "/");
		if (!path)
			return (ft_free2d_str(path), NULL);
		i++;
	}
	return (path);
}

static void	ft_create_heredoc(t_spcmd *spcmd)
{
	char	*tmp;
	int		fd;
	int		lim_len;

	fd = open(HERE_DOC_PATH, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		ft_prterr(7);
	lim_len = ft_strlen(spcmd->in.filename);
	while (1)
	{
		ft_putstr_fd("heredoc> ", STDOUT_FILENO);
		tmp = readline(STDIN_FILENO);
		// if (!(tmp))
		// 	ft_gnl_err(px);
		if (ft_strncmp(av[2], tmp, lim_len) == 0 && tmp[lim_len] == '\n')
			break ;
		ft_putstr_fd(tmp, fd);
		free (tmp);
	}
	free (tmp);
	close(fd);
}

int	ft_open_infile(t_spcmd *spcmd)
{
	int	fd_in;

	fd_in = 0;
	if (spcmd->in.have)
	{
		if (spcmd->in.rdrt == heredoc)
		{
			ft_create_heredoc()
			fd_in = open(HERE_DOC_PATH, O_RDONLY);
		}
		else
			fd_in = open(av[1], O_RDONLY);
	}
	return (fd_in);
}

char	*ft_fcmd(char **path, char *cmd, char *av)
{
	char	*pathname;
	int		i;

	i = 0;
	if (access(cmd, F_OK) == 0)
		return (ft_double_free(path), pathname = ft_strjoin("", cmd));
	if (ft_strchr(cmd, '/') && access(cmd, F_OK) != 0)
		ft_prterr(NO_INFILE, av, 2);
	while (path[i])
	{
		pathname = ft_strjoin(path[i], cmd);
		if (access(pathname, F_OK) == 0)
			return (ft_double_free(path), pathname);
		free (pathname);
		i++;
	}
	pathname = ft_strdup(cmd);
	ft_double_free(cmd);
	ft_double_free(path);
	ft_prterr(COM_ERR, pathname, 127);
	return (NULL);
}

void	ft_fork_child(t_spcmd spcmd)
{
	px->pid[px->i] = fork();
	if (px->pid[px->i] == -1)
		ft_fork_err(px, errno);
	if (px->pid[px->i] == 0)
	{
		char	*pathname;
		free(px->pid);
		px->cmd_i = px->i + 2 + px->here_doc;
		if (spcmd.in)
			infd = ft_open_infile(spcmd.in);
		if (spcmd.out)
			outfd = ft_open_outfile(spcmd.out);
		if (spcmd.pipe)
			//dopipe;
		ft_close_pipe(px);
		pathname = ft_fcmd(path, cmd, av[px->cmd_i]);
		if (execve(pathname, spcmd.arg, envp) == -1)
		{
			free(px->fcmd);
			ft_double_free(px->cmd);
			exit (errno);
		}
	}
}

bool	executor(t_msh *msh)
{
	int	j;
	char	**path;
	int		nb_pipe;
	int		nb_cmd;
	t_excmd excmd;

	path = ft_findpath();
	//count nb_pipe;
	ft_create_pipe(nb_pipe, nb_cmd);
	//count nb_cmd;
	if (!path)
		return (false);
	j = 0;
	while (j < msh->nb_cmd)
	{
		excmd.fd_in =  ft_open_infile(msh->spcmd[j]);
		run_command(msh->spcmd, msh->env);
		j++;
	}
	return (true);
}