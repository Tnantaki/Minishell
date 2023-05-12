#include "minishell.h"

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
		else if (ft_isquote(line[i]))
			i += have_quote(&line[i]);
		else if (ft_isoptr(line[i]))
			i += have_optr(&line[i]);
		else if (ft_iscmd(line[i]))
			i += have_cmd(&line[i]);
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
	else if (ft_isquote(**line))
		len += have_quote(*line);
	else if (ft_isoptr(**line))
		len += have_optr(*line);
	else if (ft_iscmd(**line))
		len += have_cmd(*line);
	token = (char *)malloc(sizeof(char) * (len + 1));
	while (i < len)
		token[i++] = *(*line)++;
	token[i] = '\0';
	return (token);
}

char	**lexer(char *line)
{
	int		i;
	int		ct;
	char	**tokens;

	i = 0;
	ct = count_token(line);
	tokens = (char **)malloc(sizeof(char *) * (ct + 1));
	if (!tokens)
		return (NULL);
	while (i < ct)
	{
		tokens[i] = trim_token(&line);
		if (!tokens[i])
			return (free2d_nstr(tokens, i));
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}
