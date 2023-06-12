/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prachman <prachman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:45:33 by prachman          #+#    #+#             */
/*   Updated: 2023/06/12 18:42:47 by prachman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int ft_export(void)
{
	t_buin_cmd  buin;
	char        **env;
	char    	*tmp;
	int         size;
	int         i;
	int     j;

	env = get_env();
	size = 0;
	while (env[size])
		size++;
	buin.tmp_env = (char **)malloc(sizeof(char *) * size + 1);
	i = 0;
	while (env[i])
	{
		buin.tmp_env[i] = ft_strdup(env[i]);
		i++;
	}
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size && buin.tmp_env[j + 1])
		{
			if (ft_strcmp(buin.tmp_env[j], buin.tmp_env[j + 1]) > 0)
			{
				tmp = buin.tmp_env[j];
				buin.tmp_env[j] = buin.tmp_env[j + 1];
				buin.tmp_env[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (buin.tmp_env[i])
	{
		printf("%s\n",buin.tmp_env[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}