#include "minishell.h"

bool	ft_isspace(int c)
{
	if (c == ' ' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\r')
		return (true);
	return (false);
}

bool	ft_isquote(int c)
{
	if (c == '\'' || c == '\"')
		return (true);
	return (false);
}

bool	ft_isoptr(int c)
{
	if (c == '<' || c == '>' || c == '|')
		return (true);
	return (false);
}

bool	ft_iscmd(int c)
{
	if (!ft_isspace(c) && !ft_isquote(c) && !ft_isoptr(c))
		return (true);
	return (false);
}
