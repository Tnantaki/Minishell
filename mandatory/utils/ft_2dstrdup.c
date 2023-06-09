#include "msh_utils.h"

char	**ft_2dstrdup(char **str)
{
	char	**dup;
	size_t	j;

	if (!str)
		return (NULL);
	dup = (char **)malloc(sizeof(char *) * (ft_2dstrlen(str) + 1));
	if (!dup)
		return (NULL);
	j = 0;
	while (str[j])
	{
		dup[j] = ft_strdup(str[j]);
		if (!(dup[j]))
			return (ft_free2dnstr(dup, j));
		j++;
	}
	dup[j] = NULL;
	return (dup);
}
