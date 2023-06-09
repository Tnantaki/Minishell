#include "msh_utils.h"

bool	ft_isquote(int c)
{
	if (c == '\'' || c == '\"')
		return (true);
	return (false);
}
