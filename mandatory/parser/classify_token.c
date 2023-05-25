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

t_type	token_type(char *token, t_type pre_type)
{
	if (*token == '<')
		return (RDRT_IN);
	else if (*token == '>')
		return (RDRT_OUT);
	else if (ft_ispipe(*token))
		return (PIPE);
	else if (pre_type == RDRT_IN || pre_type == RDRT_OUT)
		return (FILENAME);
	else
		return (ARGUMENT);
}

bool	classify_token(t_msh *msh)
{
	t_type	*type;
	int		nb_pipe;
	int		j;
	
	type = (t_type *)malloc(sizeof(t_type) * msh->nb_tk);
	if (!type)
		return (perror("Error malloc"), false);
	j = 0;
	nb_pipe = 0;
	while (j < msh->nb_tk)
	{
		if (j == 0)
			type[j] = token_type(msh->tokens[j], VOID);
		else
			type[j] = token_type(msh->tokens[j], type[j - 1]);
		if (type[j] == PIPE)
			nb_pipe++;
		j++;
	}
	msh->tk_type = type;
	msh->nb_pipe = nb_pipe;
	msh->nb_cmd = nb_pipe + 1;
	return (true);
}
