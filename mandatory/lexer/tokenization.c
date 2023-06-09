#include "minishell.h"

// Token : be separate by 
// - White-space
// - Redirection
// - Quotes

static int	count_token(char *line)
{
	int		i;
	int		ct;

	i = 0;
	ct = 0;
	while (line[i])
	{
		while (line[i] && ft_isspace(line[i]))
			i++;
		if (!line[i])
			break ;
		else if (line[i] == '\'')
			i += ft_1quote_len(&line[i]);
		else if (line[i] == '\"')
			i += ft_2quote_len(&line[i]);
		else if (ft_isoptr(line[i]))
			i += ft_optr_len(&line[i]);
		else if (ft_iscmd(line[i]))
			i += ft_cmd_len(&line[i]);
		ct++;
	}
	return (ct);
}

static char	*trim_token(char **line)
{
	char	*token;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (**line && ft_isspace(**line))
		(*line)++;
	if (!(**line))
		return (NULL);
	else if (**line == '\'')
		len += ft_1quote_len(*line);
	else if (**line == '\"')
		len += ft_2quote_len(*line);
	else if (ft_isoptr(**line))
		len += ft_optr_len(*line);
	else if (ft_iscmd(**line))
		len += ft_cmd_len(*line);
	token = (char *)malloc(sizeof(char) * (len + 1));
	while (i < len)
		token[i++] = *(*line)++;
	token[i] = '\0';
	return (token);
}

bool	tokenization(char *line, t_msh *msh)
{
	int		i;
	int		ct;
	char	**tokens;

	i = 0;
	ct = count_token(line);
	tokens = (char **)malloc(sizeof(char *) * (ct + 1));
	if (!tokens)
		return (false);
	while (i < ct)
	{
		tokens[i] = trim_token(&line);
		if (!tokens[i])
			return (ft_free2dnstr(tokens, i), false);
		i++;
	}
	tokens[i] = NULL;
	msh->tokens = tokens;
	msh->nb_tk = ct;
	return (true);
}
