#include "minishell.h"

bool	ft_isenvar(int c)
{
	if (c == '?' || c == '#' || c == '@'
		|| c == '-' || c == '!' || c == '*')
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

bool	ft_isoptr(int c)
{
	if (c == '<' || c == '>' || c == '|')
		return (true);
	return (false);
}
