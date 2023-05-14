#include "minishell.h"

//valid qoute : syntax error unclosed single quote
//valid qoute : syntax error unclosed double quote
//valid parenthesis : syntax error unclosed parenthesis
//valid pipe :syntax error near unexpected token '|'
// Can have mutiple redirec but only last one will work.

bool	valid_tokens(char **tokens)
{
	(void)tokens;
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