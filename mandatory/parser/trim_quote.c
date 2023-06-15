#include "minishell.h"

static char	*strcpy_inquote(char **line)
{
	char	*token;
	int		i;
	int		len;
	
	i = 0;
	len = 0;
	if (**line == '\'')
		len += ft_1quote_len(*line) - 2;
	else if (**line == '\"')
		len += ft_2quote_len(*line) - 2;
	token = (char *)malloc(sizeof(char) * (len + 1));
	if (!token)
		return (NULL);
	(*line)++;
	while (i < len)
		token[i++] = *(*line)++;
	token[i] = '\0';
	return (token);
}

static char	*strcpy_outquote(char **line)
{
	char	*token;
	int		i;
	int		len;
	
	i = 0;
	len = 0;
	if (ft_isoptr(**line))
		len += ft_optr_len(*line);
	else if (ft_iscmd(**line))
		len += ft_cmd_len(*line);
	token = (char *)malloc(sizeof(char) * (len + 1));
	if (!token)
		return (NULL);
	while (i < len)
		token[i++] = *(*line)++;
	token[i] = '\0';
	return (token);
}

char	*trim_!quote(char *token)
{
	int	i;

	i = 0;
	while (token[i])
	{

	}
}

char	**trim_quote(char **tokens)
{
	int	j;
	int	i;

	j = 0;
	while (tokens[j])
	{
		i = 0;
		while (tokens[j][i])
		{

			i++;
		}
		// trim_quote_token(tokens[j])
		j++;
	}
	// char	*token;

	// token = NULL;
	// while (**line && ft_isspace(**line))
	// 	(*line)++;
	// if (**line == '\'' || **line == '\"')
	// 	token = strcpy_inquote(line);
	// else if (ft_isoptr(**line) || ft_iscmd(**line))
	// 	token = strcpy_outquote(line);
	// if (!token)
	// 	return (NULL);
	// return (token);
}