#include "minishell.h"

void	swap_str(char *str1, char *str2)
{
	int	i;
	// char	*tmp;

	i = 0;
	// tmp = ft_strdup(str2);
	// while (str1[i] || tmp[i])
	if (ft_strlen(str1) < ft_strlen(str2))
	{
		free(str1);
		str1 = (char *)malloc(sizeof(char) * ft_strlen(str2) + 1);
	}
	// while (str1[i] || str2[i])
	while (str2[i])
	{
		// str1[i] = tmp[i];
		str1[i] = str2[i];
		// printf("loop:%s\n", tmp);
		i++;
	}
	// str1[i] = '\0';
	// str2 = tmp;
	// printf("str2:%s\n", str2);
	// free(str2);
	// printf("str2:%s\n", str2);
	// printf("str1%s\n", str1);
		
}

int ft_unset(char **arg, t_buin_cmd *buin)
{
	int 		i;
	int 		j;
	// int 		k;
	// char		*tmp;
	// t_buin_cmd  *buin;

	if (store_env(buin) > 0) // get env
		return (EXIT_FAILURE);
	i = 0;
	while (arg[i])
	{
		j = 0;
		while (buin->env[j])
		{
			if (ft_strncmp(arg[i], buin->env[j], ft_strlen(arg[i])) == 0) //find variable name
			{
				if (buin->env[j][ft_strlen(arg[i])] == '=') // if the name is correct, enter the clause
				{
					printf("before:%s\n", buin->env[j]);
					buin->env[j] = NULL;
					printf("after:%s\n", buin->env[j]);
					if (buin->env[j] == NULL)
						printf("this is null\n");
					free(buin->env[j]);
				}
			}
			j++;
		}
		i++;
	}
	return(EXIT_SUCCESS);
}
// int ft_unset(char **arg)
// {
// 	int 		i;
// 	int 		j;
// 	// int 		k;
// 	// char		*tmp;
// 	t_buin_cmd  *buin;

// 	if (store_env(buin) > 0) // get env
// 		return (EXIT_FAILURE);
// 	i = 0;
// 	while (arg[i])
// 	{
// 		j = 0;
// 		while (buin.env[j])
// 		{
// 			if (ft_strncmp(arg[i], buin.env[j], ft_strlen(arg[i])) == 0) //find variable name
// 			{
// 				if (buin.env[j][ft_strlen(arg[i])] == '=') // if the name is correct, enter the clause
// 				{
// 					// tmp = ft_strdup(buin.env[j + 1]);
// 					// // swap_str(buin.env[j], buin.env[j + 1]);
// 					// printf("before: %s\n", buin.env[j]);
// 					// swap_str(buin.env[j], tmp);
// 					// printf("after: %s\n", buin.env[j]);
// 					// free(buin.env[j + 1]);
// 					// free(buin.env[j]);
// 					printf("before:%s\n", buin.env[j]);
// 					buin.env[j] = NULL;
// 					printf("after:%s\n", buin.env[j]);
// 					if (buin.env[j] == NULL)
// 						printf("this is null\n");
// 					free(buin.env[j]);
// 				}
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	return(EXIT_SUCCESS);
// }