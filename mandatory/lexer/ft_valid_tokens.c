#include "minishell.h"

//valid qoute : syntax error unclosed single quote
//valid qoute : syntax error unclosed double quote
//valid parenthesis : syntax error unclosed parenthesis
//valid pipe :syntax error near unexpected token '|'
// Can have mutiple redirec but only last one will work.

typedef enum e_type_token
{
	VOID,
	RD_IN,
	RD_OUT,
	PIPE,
	FILENAME,
	CMD,
	ARG,
}	t_type;

t_type	token_type(char *token, t_type pre_type)
{
	if (pre_type == VOID)
	{
		if (ft_isoptr(*token))
			return (ft_what_optr(token));
		else if (ft_iscmd(*token))
			return (CMD);
	}
	else if (pre_type == RD_IN || pre_type == RD_OUT)
		return (FILENAME);
	else if (pre_type == CMD)
	{
		if (ft_isoptr(*token))
			return (ft_what_optr(token));
		else if (*token == '|')
			return (PIPE);
		else if (ft_iscmd(*token))
			return (ARG);
		else if (*token == '>' *token == '>>')
			return (RD_OUT);
	}

	else if (ft_iscmd(*token))
	else if (ft_iscmd(*token))
		return (ARG);
}

int	classify_token(char **tokens, int ct)
{
	t_type	*type;
	t_type	pre_type;
	int			j;
	
	j = 0;
	type = (t_type *)malloc(sizeof(t_type) * (ct + 1));
	pre_type = VOID;
	while (j < ct)
	{
		type[j] = token_type(tokens[j], pre_type);
		pre_type = type[j];
		j++;
	}
}

bool	valid_tokens(char **tokens)
{
	return (true);

	// int		j;
	// size_t	ct;

	// j = 0;
	// ct = ft_2d_strlen(tokens)
	// while (tokens[j])
	// {
	// 	if (ft_isrdrt(tokens[j]))
	// 		j++;
	// 	while (line[i] && ft_isspace(line[i]))
	// 		i++;
	// 	if ()
	// 	if (!line[i])
	// 		break ;
	// 	else if (ft_isquote(line[i]))
	// 		i += ft_quote_len(&line[i]);
	// 	else if (ft_isoptr(line[i]))
	// 		i += ft_optr_len(&line[i]);
	// 	else if (ft_iscmd(line[i]))
	// 		i += ft_cmd_len(&line[i]);
	// }
}
	// while (tokens[j])
	// {
	// 	else if (!spcmd->cmd && ft_iscmd(tokens[j]))
	// 		spcmd->cmd = tokens[j];
	// 	else if (!cpcmd->arg && ft_isarg(tokens[j]))
	// 	else if (!cpcmd->pipe && ft_ispipe(tokens[j]))
	// 	if (cpcmd->pipe)
	// 	j++;
	// }