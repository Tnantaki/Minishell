#include "minishell.h"

static int	countword(char **str)
{
	int	cw;

	cw = 0;
	while (str[cw])
		cw++;
	return (cw);
}

char **dup_envp(char **str)
{
	int	cw;
	int	j;
	int	i;
	char	**dup;

	if (!str)
		return (NULL);
	cw = countword(str);
	dup = (char **)malloc(sizeof(char *) * (cw + 1));
	while (str[i])
	{
		dup[i] = str[i];
		if (!(dup[i]))
			return ()
	}
	dup[i] = NULL;
	return (dup);
}