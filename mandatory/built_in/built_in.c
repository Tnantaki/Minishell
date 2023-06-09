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

bool	is_built_in(char *cmd, t_buin *buin)
{
	if (ft_strcmp(cmd, "echo") == 0)
		return (*buin = e_echo, true);
	else if (ft_strcmp(cmd, "cd") == 0)
		return (*buin = e_cd, true);
	else if (ft_strcmp(cmd, "pwd") == 0)
		return (*buin = e_pwd, true);
	else if (ft_strcmp(cmd, "export") == 0)
		return (*buin = e_export, true);
	else if (ft_strcmp(cmd, "unset") == 0)
		return (*buin = e_unset, true);
	else if (ft_strcmp(cmd, "env") == 0)
		return (*buin = e_env, true);
	else if (ft_strcmp(cmd, "exit") == 0)
		return (*buin = e_exit, true);
	else
		return (false);
}

bool	buin_execution(t_buin buin, char **arg)
{
	// int	status;

	// status = 0;
	if (buin == e_echo)
		ft_echo(arg);

	return (true);
	// exit(status);
}