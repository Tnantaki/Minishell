#include "msh_utils.h"

bool	ft_isvar(int c)
{
	if (c == '_' || ft_isalpha(c) || ft_isdigit(c))
		return (true);
	return (false);
}
