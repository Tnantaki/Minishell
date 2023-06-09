#include "minishell.h"

// static char	*search_var2(char *env, char *var)
// {
// 	int	i;

// 	i = 0;
// 	if (!env || !var)
// 		return (NULL);
// 	while (var[i])
// 	{
// 		if (env[i] != var[i])
// 			return (NULL);
// 		i++;
// 	}
// 	if (env[i] == '=')
// 		return (&env[i + 1]);
// 	return (NULL);
// }

// static char	*search_var(char **env, char *var)
// {
// 	int		j;
// 	char	*value;

// 	if (!var)
// 		return (NULL);
// 	j = 0;
// 	while (env[j])
// 	{
// 		value = search_var2(env[j], var);
// 		if (value)
// 		{
// 			value = ft_strdup(value);
// 			if (!value)
// 				return ((char *)ft_calloc(1, sizeof(char)));
// 			return (value);
// 		}
// 		j++;
// 	}
// 	return ((char *)ft_calloc(1, sizeof(char)));
// }

// function will remove Variable string and replace with Value string.
// str : String that have Variable string in it.
// var : Variable string.
// i_var : first index of var in string.
// value : Value string.
// - In case of value = NULL it be replace by empty string

char *ft_strinsert(char *str, char *var, int i_var, char *value)
{
	int		i;
	int		j;
	int		len_value;
	int		len_var;
	char	*new;

	if (!value)
		value = "";
	len_value = strlen(value);
	len_var = strlen(var);
	new = malloc(sizeof(char) * (strlen(str) - len_var + len_value + 1));
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (i < i_var)
		new[i++] = str[j++];
	while (*value)
		new[i++] = *value++;
	j += len_var;
	while (str[j])
		new[i++] = str[j++];
	return (new[i] = '\0', free(str), free(var), new);
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
			// else if (token[i + 1] == '$')
			// {
			// 	len = 2;
			// 	value = ft_itoa(getppid());//This function not allow
			// 	if (!value)
			// 		return (NULL);
			// 	token = ft_str_insert(token, i, len, value);
			// 	len = ft_strlen(value);
			// 	free(value);
			// 	if (!token)
			// 		return (NULL);
			// 	i += len;
			// }
			else if (token[i + 1] == '$' || ft_isenvar(token[i + 1]))
				i += 2;
			else if (ft_isvar(token[i + 1]))
			{
				var = ft_strndup(&token[i], ft_var_len(&token[i]));
				if (!var)
					return (NULL);
				// value = search_var(get_env(), var + 1);
				value = getenv(var + 1);
				// printf("value:%s\n", value);
				token = ft_strinsert(token, var, i, value);
				len = ft_strlen(value);
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
