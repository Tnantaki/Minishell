#include "minishell.h"

int	store_env(t_buin_cmd *buin)
{
	int			i;
	char    	**env;

	i = 0;
	env = get_env();
	while (env[i])
		i++;
	buin->env = (char **)malloc(sizeof(char *) * i + 1);
	if (!buin->env) //probably need to quit the process
		return (EXIT_FAILURE);
	i = 0;
	while (env[i])
	{
		buin->env[i] = env[i];
		i++;
	}
	return (EXIT_SUCCESS);
}

int ft_env(char **arg, t_buin_cmd *buin)
{
	int			i;
	// t_buin_cmd	buin;

	// if (store_env(buin) > 0)
	// 	return (EXIT_FAILURE);
	// printf("in the ft_env\n");
	// printf("%s\n", buin->env[0]);
	// if (ft_strcmp(arg[0], "env") == 0)
	(void) arg;
	printf("111111111\n");
	if (buin->env == NULL)
	{
		printf("get new env!!!!!!!\n");
		if (store_env(buin) > 0)
			return (EXIT_FAILURE);
	}
	printf("2222222\n");
	i = 0;
	while(buin->env[i])
	{
		if (buin->env[i] != NULL)
			printf("%s\n", buin->env[i]);
		// else
			// printf("111111111\n");
		i++;
	}
	// printf("3333333\n");
	return (EXIT_SUCCESS);
}