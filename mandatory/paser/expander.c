#include "minishell.h"

static char	*get_var(char *token)
{
	char	*tmp;
	char	*var;

	tmp = token;
	while (*token && !ft_isvar(*token))
		token++;
	token[var_len(token)] = '\0';
	var = ft_strdup(token);
	if (!var)
		return (NULL);
	free(tmp);
	return (var);
}

static char	*search_var(char *env, char *var)
{
	int	i;

	i = 0;
	if (!env || !var)
		return (NULL);
	while (var[i])
	{
		if (env[i] != var[i])
			return (NULL);
		i++;
	}
	if (env[i] == '=')
		return (&env[i + 1]);
	return (NULL);
}

static char	*get_value(char *token, char **env)
{
	int		j;
	char	*var;
	char	*value;

	var = get_var(token);
	if (!var)
		return (NULL);
	j = 0;
	while (env[j])
	{
		value = search_var(env[j], var);
		if (value)
		{
			value = ft_strdup(value);
			if (!value)
				return (NULL);
			return (value);
		}
		j++;
	}
	return ("");
}

char	**expander(char **tokens)
{
	int		j;
	int		i;
	char	**env;

	j = 0;
	i = 0;
	env = get_env();
	while (tokens[j])
	{
		if (tokens[j][i] && tokens[j][i] == '$')
		{
			tokens[j] = get_value(tokens[j], env);
		}
		j++;
	}
	return (tokens);
}