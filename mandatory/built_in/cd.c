/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prachman <prachman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 12:37:04 by prachman          #+#    #+#             */
/*   Updated: 2023/06/08 13:15:33 by prachman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int cd_home(t_buin_cmd *buin, char **env)
{
    int i;
    int ch;
    
    buin->cur_dir = getenv("HOME");
    ch = chdir(buin->cur_dir);
    if (ch < 0)
    {
        perror("error");
        return (EXIT_FAILURE);
    }
    i = 0;
    while (env[i]) // update PWD
    {
        if (ft_strncmp(env[i], "PWD", ft_strlen("PWD")) == 0)
        {
            buin->cur_dir = ft_strjoin("PWD=", buin->cur_dir);
            env[i] = buin->cur_dir;
        }
        i++;
    }
    // printf("\n");
    // printf("\n");
    // printf("\n");
    // printf("\n");
	// for (int i = 0; env[i]; i++)
	// 	printf("%s\n", env[i]);
    return (EXIT_SUCCESS);
}

int	ft_cd(char **arg)
{
    int         i;
    int         ch;
	char		**env;
	t_buin_cmd	buin;

    buin.old_dir = NULL;
	// if (ft_strcmp(arg[1], "-") == 0) 
    // {
    // }
	buin.old_dir = getcwd(buin.old_dir, 0);
	// printf("%s\n", buin.old_dir);
    i = 0;
	env = get_env();
    while (env[i]) // update OLDPWD
    {
        if (ft_strncmp(env[i], "OLDPWD", ft_strlen("OLDPWD")) == 0)
        {
            buin.old_dir = ft_strjoin("OLDPWD=", buin.old_dir);
            env[i] = buin.old_dir;
        }
        i++;
    }
    if (!arg[1])
        return (cd_home(&buin, env));
    ch = chdir(arg[1]);
    if (ch < 0)
    {
        perror("error");
        return (EXIT_FAILURE);
    }
    buin.cur_dir = getcwd(buin.cur_dir, 0);
    i = 0;
    while (env[i]) // update PWD
    {
        if (ft_strncmp(env[i], "PWD", ft_strlen("PWD")) == 0)
        {
            buin.cur_dir = ft_strjoin("PWD=", buin.cur_dir);
            env[i] = buin.cur_dir;
        }
        i++;
    }
    // printf("\n");
    // printf("\n");
    // printf("\n");
    // printf("\n");
	// for (int i = 0; env[i]; i++)
	// 	printf("%s\n", env[i]);
	return (EXIT_SUCCESS);
}
