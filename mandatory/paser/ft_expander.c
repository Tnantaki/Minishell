#include "minishell.h"

static char	*search_var2(char *env, char *var)
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

static char	*search_var(char **env, char *var)
{
	int		j;
	char	*value;

	if (!var)
		return (NULL);
	j = 0;
	while (env[j])
	{
		value = search_var2(env[j], var);
		if (value)
		{
			value = ft_strdup(value);
			if (!value)
				return ((char *)ft_calloc(1, sizeof(char)));
			return (value);
		}
		j++;
	}
	return ((char *)ft_calloc(1, sizeof(char)));
}

char *ft_str_insert(char *str, int i_var, int len_var, char *value)
{
	int		i;
	int		i_str;
	int		len_vl;
	int		len_str;
	char	*new;

	if (!str || !value)
		return (str);
	len_str = ft_strlen(str);
	len_vl = ft_strlen(value);
	// printf("len_str:%d\n", len_str);
	// printf("len_vl:%d\n", len_vl);
	// printf("len_var:%d\n", len_var);
	if (len_var + i_var > len_str)
		return (str);
	new = (char *)malloc(sizeof(char) * (len_str - len_var + len_vl + 1));
	if (!new)
		return (NULL);
	i = 0;
	i_str = 0;
	while (i < i_var)
		new[i++] = str[i_str++];
	while (*value)
		new[i++] = *value++;
	i_str += len_var;
	while (str[i_str])
		new[i++] = str[i_str++];
	new[i] = '\0';
	return (free(str), new);
}

char	*is_var(char *token)
{
	int		i;
	int		len;
	char	*var;
	char	*value;

	i = 0;
	while (token[i])
	{
		if (token[i] == '$')
		{
			if (!token[i + 1])
				return (token);
			else if (token[i + 1] == '$')
			{
				len = 2;
				value = ft_itoa(getppid());//This function not allow
				if (!value)
					return (NULL);
				token = ft_str_insert(token, i, len, value);
				len = ft_strlen(value);
				free(value);
				if (!token)
					return (NULL);
				i += len;
			}
			else if (ft_isvar(token[i + 1]))
			{
				len = ft_var_len(&token[i + 1]);
				var = ft_strndup(&token[i + 1], len);
				if (!var)
					return (NULL);
				value = search_var(get_env(), var);
				// printf("value:%s\n", value);
				if (!value)
					return (NULL);
				token = ft_str_insert(token, i, len + 1, value);
				len = ft_strlen(value);
				free(value);
				if (!token)
					return (NULL);
				i += len;
			}
			else
				i++;
		}
		else
			i++;
	}
	// printf("token: %s\n", token);
	return (token);
}

bool	expander(char **tokens)
{
	int		j;

	j = 0;
	while (tokens[j])
	{
		tokens[j] = is_var(tokens[j]);
		if (!tokens[j])
			return (false);
		j++;
	}
	return (true);
}
