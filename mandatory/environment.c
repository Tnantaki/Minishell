/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:03:31 by tnantaki          #+#    #+#             */
/*   Updated: 2023/06/21 15:03:33 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**set_env(char **env)
{
	static char	**stc_env = NULL;

	if (!env)
		return (stc_env);
	stc_env = env;
	return (stc_env);
}

char	**get_env(void)
{
	return (set_env(NULL));
}

char	*get_env_value(char *var)
{
	int		j;
	int		len_var;
	char	**env;

	if (!var || !(*var))
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

// Search variable in env
// return address of env that match with var
// return NULL if not found
char	**search_env_var(char *var, int var_len)
{
	int		j;
	char	**env;

	env = get_env();
	j = 0;
	while (env[j])
	{
		if (ft_strncmp(env[j], var, var_len) == 0)
		{
			if (env[j][var_len] == '\0' || env[j][var_len] == '=')
				return (env + j);
		}
		j++;
	}
	return (NULL);
}

// Check name of variable is valid
// return 1(true) : if it valid.
// return 0(false) : if it not, print error massage and change status.
bool	check_valid_var(char *var, int *status, char *cmd)
{
	int	var_len;

	var_len = 0;
	if (ft_is_1stvar(var[0]))
	{
		var_len = ft_var_len(var);
		if (var[var_len] == '\0' || var[var_len] == '=')
			return (true);
	}
	ft_prterrf(cmd, var, "': not a valid identifier\n");
	*status = 1;
	return (false);
}
