/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prachman <prachman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:45:33 by prachman          #+#    #+#             */
/*   Updated: 2023/06/13 21:16:31 by prachman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int ft_export(void)
{
	char	**env;
	char	**tmp_env;
	char    	*tmp;
	int         size;
	int         i;
	int     j;

	env = get_env();
	size = 0;
	while (env[size])
		size++;
	tmp_env = ft_2dstrdup(env);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size && tmp_env[j + 1])
		{
			if (ft_strcmp(tmp_env[j], tmp_env[j + 1]) > 0)
			{
				tmp = tmp_env[j];
				tmp_env[j] = tmp_env[j + 1];
				tmp_env[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (tmp_env[i])
		printf("%s\n",tmp_env[i++]);
	free(tmp_env);
	return (EXIT_SUCCESS);
}