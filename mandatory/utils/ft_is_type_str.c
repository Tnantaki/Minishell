#include "minishell.h"

bool	ft_iscmd(int c)
{
	if (!ft_isspace(c) && !ft_isquote(c) && !ft_isoptr(c))
		return (true);
	return (false);
}

bool	ft_isvar(int c)
{
	if (c == '_' || ft_isalpha(c) || ft_isdigit(c))
		return (true);
	return (false);
}

bool	ft_isarithmatic(char *str)
{
	if (str[0] == '(' && str[2] && str[2] == '(')
		return (true);
	else if (str[1] == '[')
		return (true);
	return (false);
}
