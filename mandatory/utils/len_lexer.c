#include "minishell.h"

int	quote_len(char *str)
{
	int	i;

	i = 1;
	while (str[i] && !ft_isquote(str[i]))
		i++;
	i++;
	return (i);
}

int	optr_len(char *str)
{
	int	i;

	i = 1;
	if (str[i] == '<' || str[i] == '>')
		i++;
	return (i);
}

int	cmd_len(char *str)
{
	int	i;

	i = 1;
	while (str[i] && ft_iscmd(str[i]))
		i++;
	return (i);
}

int	var_len(char *line)
{
	int	i;

	i = 1;
	while (line[i] && ft_isvar(line[i]))
		i++;
	return (i);
}