/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:25:22 by tnantaki          #+#    #+#             */
/*   Updated: 2023/06/12 13:25:23 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char *get_var(char *token, int *i)
{
	char	*var;
	char	*value;
	int		var_len;

	var_len = 0;
	if (ft_is_1stvar(token[*i + 1]))
		var_len = ft_var_len(&token[*i + 1]);
	else if (ft_isspecial(token[*i + 1]))
		var_len = 1;
	var = ft_strndup(&token[*i + 1], var_len);
	if (!var)
		return (NULL);
	value = get_env_value(var);
	token = ft_strinsert(token, ft_strlen(var) + 1, *i, value);
	free(var);
	if (!token)
		return (NULL);
	if (value)
		*i += ft_strlen(value);
	return (token);
}

static char *get_status(char *token, int *i)
{
	char *value;

	value = ft_itoa(g_status);
	if (!value)
		return (NULL);
	token = ft_strinsert(token, 2, *i, value);
	free(value);
	if (!token)
		return (NULL);
	*i += ft_strlen(value);
	return (token);
}

static char *is_var(char *token)
{
	int	i;
	int	in_2quote;

	i = 0;
	in_2quote = 0;
	while (token[i])
	{
		if (token[i] == '$')
		{
			if (token[i + 1] == '?')
				token = get_status(token, &i);
			else if (ft_is_1stvar(token[i + 1]) || ft_isspecial(token[i + 1])
				|| (token[i + 1]) == '\'')
				token = get_var(token, &i);
			else
				i++;
			if (!token)
				return (NULL);
		}
		else if (token[i] == '\'' && !in_2quote)
			i += ft_quote_len(&token[i], '\'');
		else if (token[i++] == '\"')
			in_2quote = (in_2quote + 1) % 2; //if in double quote will be 1
	}
	return (token);
}

bool expander(char **tokens)
{
	int	j;

	j = 0;
	while (tokens[j])
	{
		tokens[j] = is_var(tokens[j]);
		if (!tokens[j])
		{
			tokens[j] = ft_calloc(1, sizeof(char)); // for case of loop free to the end
			return (perror("Error malloc"), false);
		}
		j++;
	}
	return (true);
}
