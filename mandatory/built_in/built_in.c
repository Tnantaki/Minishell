#include "minishell.h"

t_buin	is_built_in(char *cmd)
{
	if (ft_strcmp(cmd, "echo") == 0)
		return (ECHO);
	else if (ft_strcmp(cmd, "cd") == 0)
		return (CD);
	else if (ft_strcmp(cmd, "pwd") == 0)
		return (PWD);
	else if (ft_strcmp(cmd, "export") == 0)
		return (EXPORT);
	else if (ft_strcmp(cmd, "unset") == 0)
		return (UNSET);
	else if (ft_strcmp(cmd, "env") == 0)
		return (ENV);
	else if (ft_strcmp(cmd, "exit") == 0)
		return (EXIT);
	else
		return (NON);
}

bool	built_exec(t_buin built, char **arg)
{
	int	status;

	status = 0;
	if (built == ECHO)
		status = ft_echo(arg);
	else if (built == CD)
		status = ft_cd(arg);

	exit(status);
}