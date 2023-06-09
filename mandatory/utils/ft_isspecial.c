#include "msh_utils.h"

bool	ft_isspecial(int c)
{
	if (c == '$' || c == '#' || c == '@'
		|| c == '-' || c == '!' || c == '*')
		return (true);
	return (false);
}
