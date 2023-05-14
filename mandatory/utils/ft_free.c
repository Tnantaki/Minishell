#include "minishell.h"

char	**free2d_str(char **ptr)
{
	int	i;

	if (!ptr)
		return (NULL);
	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	return (NULL);
}

char	**free2d_nstr(char **ptr, int i)
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
