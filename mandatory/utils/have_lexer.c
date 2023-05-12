#include "minishell.h"

int	have_quote(char *line)
{
	int	i;

	i = 1;
	while (line[i] && !ft_isquote(line[i]))
		i++;
	i++;
	return (i);
}

int	have_optr(char *line)
{
	int	i;

	i = 1;
	if (line[i] == '<' || line[i] == '>')
		i++;
	return (i);
}

int	have_cmd(char *line)
{
	int	i;

	i = 1;
	while (line[i] && ft_iscmd(line[i]))
		i++;
	return (i);
}
