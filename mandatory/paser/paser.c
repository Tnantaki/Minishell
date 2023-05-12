#include "minishell.h"
int	is_var(char *token)
{
	int	i;

	i = 0;
	if (token[i] && token[i] == '$')
	{
		i++;
		if (token[i] && ft_isdigit(token[i]))
			return (0);
		while (token[i] && ft_isvar(token[i]))
	}
}

char	**expander(char **token)
{
	int	j;

	j = 0;
	while (token[j])
	{
		is_var(token[j])
		j++;
	}
}


int	paser(char **tokens)
{
	tokens = expander(tokens);
	return (0);
}