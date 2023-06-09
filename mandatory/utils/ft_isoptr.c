#include "msh_utils.h"

bool	ft_isoptr(int c)
{
	if (c == '<' || c == '>' || c == '|')
		return (true);
	return (false);
}