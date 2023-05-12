#include "minishell.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_2d_strlen(char **str)
{
	size_t	cw;

	cw = 0;
	while (str[cw])
		cw++;
	return (cw);
}

char	*ft_strdup(char *str)
{
	char	*dst;
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	dst = (char *)malloc((sizeof(char)) * (ft_strlen(str) + 1));
	if (!dst)
		return (NULL);
	while (str[i])
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	**ft_2d_strdup(char **str)
{
	char	**dup;
	size_t	j;

	if (!str)
		return (NULL);
	dup = (char **)malloc(sizeof(char *) * (ft_2d_strlen(str) + 1));
	if (!dup)
		return (NULL);
	j = 0;
	while (str[j])
	{
		dup[j] = ft_strdup(str[j]);
		if (!(dup[j]))
			return (free2d_nstr(dup, j));
		j++;
	}
	dup[j] = NULL;
	return (dup);
}
