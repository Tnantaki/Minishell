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
	int		status;
	int 		i;
	int 		j;
	char	**env;

	status = 0;
	if (arg[1] == NULL)
		return (ft_prterr("unset: not enough arguments\n"), 1);
	env = get_env();
	i = 0;
	while (arg[i])
	{
		if (!ft_is_1stvar(arg[i][0]))
		{
			ft_prterr("unset: `");
			ft_prterr(arg[i]);
			ft_prterr("': not a valid identifier\n");
			status = 1;
			i++;
			continue ;
		}
		j = 0;
		while (env[j])
		{
			if (ft_strncmp(arg[i], env[j], ft_strlen(arg[i])) == 0) //find variable name
			{
				if (env[j][ft_strlen(arg[i])] == '=') // if the name is correct, enter the clause
				{
					del_env(env, j);
				}
			}
			j++;
		}
		i++;
	}
	return(status);
}
