/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truangsi <truangsi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:37:04 by prachman          #+#    #+#             */
/*   Updated: 2023/06/07 12:37:51 by truangsi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_getcwd(t_buin_cmd *buin)
{
	char	cwd[256];

	if (getcwd(cwd, sizeof(cwd)) == NULL) //check if the cwd is really changed
	{
		perror("error");
		return (EXIT_FAILURE);
	}
	printf("currently at: %s\n", cwd); //!can be deleted later
	buin->cur_dir = cwd;
	return (EXIT_SUCCESS);
}

int	ft_cd(char **arg)
{
	char		**env;
	t_buin_cmd	buin;

	arg = NULL;
	buin.old_dir = getcwd(buin.old_dir, 0);
	printf("%s\n", buin.old_dir);
	env = get_env();
	// while (ft_strncmp[i], "OLDPWD", ft_strlen("OLDPWD") == 0)
	// {

	// }
	return (EXIT_SUCCESS);
}

// int	ft_cd(char **arg)
// {
// 	int			ch;
// 	// char    *cur_dir;
// 	char		**env;
// 	t_buin_cmd	buin;

// 	env = get_env();
// 	// for (int i = 0; env[i]; i++)
// 	// 	printf("%s\n", env[i]);
// 	// printf("\n");
// 	// printf("\n");
// 	// printf("\n");
// 	// printf("\n");
// 	// printf("%s\n", env[13]);
// 	// if (ft_strncmp(env[13], "OLDPWD", ft_strlen("OLDPWD")) == 0)
// 	// {
// 	// 	printf("111111111\n");
// 	// 	// free(env[13]);
// 	// 	env[13] = "hello";
// 	// 	// printf("%s\n", env[13]);
// 	// }
// 	// for (int i = 0; env[i]; i++)
// 	// 	printf("%s\n", env[i]);

// 	if (arg[1] == NULL) // go home
// 	{
// 		ft_getcwd(&buin); // get cwd
// 		buin.old_dir = buin.cur_dir; //update old_dir
// 		printf("old: %s\n", buin.old_dir);
// 		buin.cur_dir = getenv("HOME"); //cur = home
// 		ch = chdir(buin.cur_dir);
// 		printf("home: %s\n", buin.cur_dir);
// 		// return (EXIT_SUCCESS);
// 	}
// 	else if (ft_strcmp(arg[1], "-") == 0)
// 	{
// 		buin.old_dir = buin.cur_dir;
// 		ft_getcwd(&buin); // get cw d
// 		ch = chdir(buin.cur_dir);
// 		ft_getcwd(&buin);
// 		// return (EXIT_SUCCESS);
// 	}
// 	else
// 	{
// 		ch = chdir(arg[1]); //change the cwd (current working dir)
// 		if (ch < 0 && arg[1] != NULL)
// 		{
// 			perror("error");
// 			return (EXIT_FAILURE);
// 		}
// 	}
// 	printf("change success\n");
// 	// printf("%s\n", arg[1]);
// 	return (EXIT_SUCCESS);
// }
