#include "msh_utils.h"

bool	ft_iscmd(int c)
{
	if (!ft_isspace(c) && !ft_isquote(c) && !ft_isoptr(c))
		return (true);
	return (false);
}
