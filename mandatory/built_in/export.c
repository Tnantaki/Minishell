/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prachman <prachman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:45:33 by prachman          #+#    #+#             */
/*   Updated: 2023/06/09 20:00:17 by prachman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int ft_export(void)
{
    char    **env;
    char    **exp;
    char    *tmp;
    int     size;
    int     i;
    int     j;

    env = get_env();
    // printf("%s\t%zu\n", env[0], ft_strlen(env[0]));
    size = 0;
    while (env[size])
        size++;
    exp = (char **)malloc(sizeof(char *) * size);
    i = 0;
    j = 0;
    tmp = env[0];
    // while (env[i])
    // {
    //     // size = ft_strlen(env[i]);
    //     j = 0;
    //     while (tmp[j] != '=' && env[i][j] != '=')
    //     {
    //         if (tmp[j] > env[i][j])
    //         {
    //             break ;
    //         }
    //     }
    // }
    return (EXIT_SUCCESS);
}