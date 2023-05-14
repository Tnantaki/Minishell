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

bool	ft_ispid(int c)
{
	if (c == '$')
		return (true);
	return (false);
}

bool	ft_iscmdsub(int c)
{
	if (c == '(')
		return (true);
	return (false);
}

bool	ft_isvarsub(int c)
{
	if (c == '{')
		return (true);
	return (false);
}

bool	ft_isenvar(int c)
{
	if (c == '?' || c == '#' || c == '@'
		|| c == '-' || c == '!' || c == '*')
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

bool	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (true);
	return (false);
}

bool	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

bool	ft_isvar(int c)
{
	if (c == '_' || ft_isalpha(c) || ft_isdigit(c))
		return (true);
	return (false);
}