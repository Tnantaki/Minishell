#include "msh_utils.h"

char	**ft_free2dnstr(char **ptr, int i)
{
	if (!ptr)
		return (NULL);
	i--;
	while (i >= 0)
	{
		free((void *)ptr[i]);
		i--;
	}
	free(ptr);
	return (NULL);
}