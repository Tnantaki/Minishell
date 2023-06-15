/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:29:14 by tnantaki          #+#    #+#             */
/*   Updated: 2023/06/12 13:29:15 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**set_env(char **env)
{
	static char **stc_env = NULL;

	if (!env)
		return (stc_env);
	stc_env = env;
	return (stc_env);
}

char **get_env(void)
{
	return (set_env(NULL));
}

char	*search_var(char *var)
{
	int		j;
	int		len_var;
	char	**env;

	if (!var)
		return (NULL);
	env = get_env();
	j = 0;
	len_var = ft_strlen(var);
	while (env[j])
	{
		if (ft_strncmp(env[j], var, len_var) == 0 && env[j][len_var] == '=')
			return (ft_strdup(env[j] + len_var + 1));
		j++;
	}
	return (NULL);
}