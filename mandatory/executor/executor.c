#include "minishell.h"

static void	ft_create_here_doc(spcmd, t_pipe *px)
{
	char	*tmp;
	int		fd;
	int		len;

	fd = open(HERE_DOC_PATH, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		ft_prterr(HERE_DOC, HERE_DOC_PATH, errno);
	len = ft_strlen(av[2]);
	while (1)
	{
		ft_putstr_fd("heredoc> ", STDOUT_FILENO);
		tmp = get_next_line(STDIN_FILENO);
		if (!(tmp))
			ft_gnl_err(px);
		if (ft_strncmp(av[2], tmp, len) == 0 && tmp[len] == '\n')
			break ;
		ft_putstr_fd(tmp, fd);
		free (tmp);
	}
	free (tmp);
	close(fd);
}

int	run_command(t_spcmd *spcmd, char **env)
{
	t_excmd	excmd;

	if (spcmd->in.have)
	{
		if (spcmd->in.rdrt == heredoc)
			ft_create_here_doc()
		dup2()
	}

}

bool	executor(t_msh *msh)
{
	int	j;

	j = 0;
	while (j < msh->cmd_nb)
	{
		run_command(msh->spcmd, msh->env);
		j++;
	}
	return (true);
}