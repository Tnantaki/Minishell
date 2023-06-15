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

static char	*get_var(char *token, int *i)
{
	char	*var;
	char	*value;

	var = ft_strndup(token, ft_var_len(token));
	if (!var)
		return (NULL);
	value = search_var(var + 1);
	token = ft_strinsert(token, ft_strlen(var), *i, value);
	free(var);
	if (!token)
		return (NULL);
	if (value)
		*i += ft_strlen(value);
	return (token);
}

static char	*get_status(char *token, int *i)
{
	char	*value;

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

static char	*is_var(char *token)
{
	int		i;

	i = 0;
	while (token[i])
	{
		if (token[i] == '$')
		{
			if (token[i + 1] == '?')
				token = get_status(token, &i);
			else if (ft_isspecial(token[i + 1]))
				token = get_var(token, &i);
			else if (ft_is_1stvar(token[i + 1]))
				token = get_var(token, &i);
			else
				i++;
			if (!token)
				return (NULL);
		}
		else
			i++;
	}
	return (token);
}

bool	expander(char **tokens)
{
	int	j;

	j = 0;
	while (tokens[j])
	{
		tokens[j] = is_var(tokens[j]);
		if (!tokens[j])
		{
			tokens[j] = ft_calloc(1, sizeof(char)); //for case of loop free to the end
			return (perror("Error malloc"), false);
		}
		j++;
	}
	return (true);
}
