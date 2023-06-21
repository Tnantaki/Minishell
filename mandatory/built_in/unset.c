#include "minishell.h"

void	del_env(char **env, int	j)
{
	int	i;

	free(env[j]);
	env[j] = NULL;
	i = j;
	while (env[i + 1]) //make new order
	{
		env[i] = env[i + 1];
		i++;
	}
	env[i] = NULL;
}

int ft_unset(char **arg)
{
	int			i;
	int		status;
	char	**env;

	status = 0;
	// if (arg[1] == NULL)
	// 	return (ft_prterr("unset: not enough arguments\n"), 1);
	i = 0;
	while (arg[++i])
	{
		if (!check_valid_var(arg[i], &status, "unset: `"))
			continue;
		env = search_env_var(arg[i], ft_var_len(arg[i]));
		if (env)
			del_env(env, 0);
	}
	return(status);
}
