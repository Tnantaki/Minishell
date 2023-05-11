#include "minishell.h"

bool	ft_isspace(int c)
{
	if (c == ' ' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

bool	ft_isquote(int c)
{
	if (c == '\'' || c == '\"')
		return (1);
	return (0);
}

bool	ft_isoptr(int c)
{
	if (c == '<' || c == '>' || c == '|')
		return (1);
	return (0);
}

bool	ft_iscmd(int c)
{
	if (!ft_isspace(c) && !ft_isquote(c) && !ft_isoptr(c))
		return (1);
	return (0);
}
