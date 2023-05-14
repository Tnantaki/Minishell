#include "minishell.h"

// int	ft_quote_len(char *str)
// {
// 	int	i;

// 	i = 0;
// 	if (str[i++] == '\'')
// 	{
// 		while (str[i] && str[i] != '\'')
// 			i++;
// 		return (i + 1);
// 	}
// 	else
// 	{
// 		while (str[i] && str[i] != '\"')
// 			i++;
// 		return (i + 1);
// 	}
// 	return (0);
// }
int	ft_1quote_len(char *str)
{
	int	i;

	i = 1;
	while (str[i] && str[i] != '\'')
		i++;
	if (str[i] == '\'')
		return (i + 1);
	return (0);
}

int	ft_2quote_len(char *str)
{
	int	i;

	i = 1;
	while (str[i] && str[i] != '\"')
		i++;
	if (str[i] == '\"')
		return (i + 1);
	return (0);
}

int	ft_optr_len(char *str)
{
	int	i;

	i = 1;
	if (str[i] == '<' || str[i] == '>')
		i++;
	return (i);
}

int	ft_cmd_len(char *str)
{
	int	i;

	i = 1;
	while (str[i] && ft_iscmd(str[i]))
		i++;
	return (i);
}

int	ft_var_len(char *line)
{
	int	i;

	i = 1;
	while (line[i] && ft_isvar(line[i]))
		i++;
	return (i);
}