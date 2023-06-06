#include "minishell.h"

//Copy from Toni for testing
int	ft_echo(char **args)
{
	bool	print_newline;

	print_newline = true;
	if (ft_strncmp(*args, "echo", ft_strlen(*args)) != 0)
		return (EXIT_FAILURE);
	args++;
	if (*args && ft_strncmp(*args, "-n", ft_strlen("-n") + 1) == 0)
	{
		print_newline = false;
		args++;
	}
	while (*args)
	{
		if (printf("%s", *args) != (int)ft_strlen(*args))
			return (EXIT_FAILURE);
		if (ft_strlen(*args) != 0 && *(args + 1) != NULL)
			if (printf(" ") != (int)ft_strlen(" "))
				return (EXIT_FAILURE);
		args++;
	}
	if (print_newline)
		if (printf("\n") != (int)ft_strlen("\n"))
			return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

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
	char	**env;

	status = 0;
	if (built == ECHO)
		status = ft_echo(arg);
	else if (built == CD)
		status = ft_cd(arg);

    env = get_env();
    for (int i = 0; env[i]; i++)
        printf("%s\n", env[i]);
	exit(status);
}