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
		i++;
	}
		
}

// int ft_unset(char **arg)
// {
// 	int 		i;
// 	int 		j;
// 	char	**env;

// 	env = get_env();
// 	i = 0;
// 	while (arg[i])
// 	{
// 		j = 0;
// 		while (env[j])
// 		{
// 			if (ft_strncmp(arg[i], env[j], ft_strlen(arg[i])) == 0) //find variable name
// 			{
// 				if (env[j][ft_strlen(arg[i])] == '=') // if the name is correct, enter the clause
// 				{
					
// 				}
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	return(EXIT_SUCCESS);
// }
