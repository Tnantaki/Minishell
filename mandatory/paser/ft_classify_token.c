#include "minishell.h"


bool	ft_isrdrt(int c)
{
	if (c == '<' || c == '>')
		return (true);
	return (false);
}

bool	ft_ispipe(int c)
{
	if (c == '|')
		return (true);
	return (false);
}

t_type	token_type(char *token, t_type pre_type, int *command)
{
	if (ft_isrdrt(*token))
		return (REDIRECT);
	else if (ft_ispipe(*token))
		return (PIPE);
	else if (pre_type == REDIRECT)
		return (FILENAME);
	else if (*command == 0)
		return (*command = 1, COMMAND);
	else
		return (ARGUMENT);
}

t_type	*classify_token(char **tokens, int ct)
{
	t_type	*type;
	t_type	pre_type;
	int		command;
	int		j;
	
	type = (t_type *)malloc(sizeof(t_type) * (ct + 1));
	if (!type)
		return (NULL);
	pre_type = VOID;
	command = 0;
	j = 0;
	while (j < ct)
	{
		if (pre_type == PIPE)
			command = 0;
		type[j] = token_type(tokens[j], pre_type, &command);
		if (type[0] == PIPE)
			return (ft_err_par(1), NULL);
		else if (pre_type == PIPE && type[j] == PIPE)
			return (ft_err_par(1), NULL);
		pre_type = type[j];
		j++;
	}
	return (type);
}
