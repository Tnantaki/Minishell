#include "minishell.h"

static int	count_quote(char *token)
{
	int	i;
	int	cq;

	i = 0;
	cq = 0;
	while (token[i])
	{
		if (ft_isquote(token[i]))
		{
			i += ft_quote_len(&token[i], token[i]);
			cq += 2;
		}
		else
			i++;
	}
	return (cq);
}

static char	*trim_quote_token(char *token, int cq)
{
	int		i;
	int		len;
	char	*new_token;

	new_token = (char *)malloc(sizeof(char) * (ft_strlen(token) - cq + 1));
	if (!new_token)
		return (NULL);
	i = 0;
	cq = 0;
	while (token[i + cq])
	{
		if (ft_isquote(token[i + cq]))
		{
			len = ft_quote_len(token + i + cq, token[i + cq]) - 2; //minus 2 char of 2 quote
			ft_memcpy(&new_token[i], &token[i + cq + 1], len);
			i += len;
			cq += 2;
		}
		else
		{
			new_token[i] = token[i + cq];
			i++;
		}
	}
	return (new_token[i] = '\0', new_token);
}

bool	trim_quote(char **tokens)
{
	int		j;
	int		cq;
	char	*tmp;

	j = 0;
	cq = 0;
	while (tokens[j])
	{
		cq = count_quote(tokens[j]);
		if (cq)
		{
			tmp = tokens[j];
			tokens[j] = trim_quote_token(tokens[j], cq);
			if (!tokens[j])
				return (tokens[j] = tmp, perror("Error malloc"), false);
			free(tmp);
		}
		j++;
	}
	return (true);
}
