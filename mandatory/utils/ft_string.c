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

char	*ft_strndup(char *str, size_t n)
{
	char	*dst;
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	dst = (char *)malloc((sizeof(char)) * (n + 1));
	if (!dst)
		return (NULL);
	while (i < n)
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

int	ft_atoi(const char *str)
{
	long long	nb;
	int			negative;
	int			i;

	i = 0;
	nb = 0;
	negative = 1;
	while ((str[i] && str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			negative = -1;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + (str[i++] - '0');
	return (nb * negative);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	i;
	size_t	len;

	if (count >= SIZE_MAX && size >= SIZE_MAX)
		return (NULL);
	len = count * size;
	str = malloc(len);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
		str[i++] = 0;
	return (str);
}
