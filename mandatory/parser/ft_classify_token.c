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
	int		nb_cmd;
	int		j;
	
	type = (t_type *)malloc(sizeof(t_type) * msh->nb_tk);
	if (!type)
		return (perror("Error malloc"), false);
	j = 0;
	nb_cmd = 1;
	while (j < msh->nb_tk)
	{
		if (j == 0)
			type[j] = token_type(msh->tokens[j], VOID);
		else
			type[j] = token_type(msh->tokens[j], type[j - 1]);
		if (type[j] == PIPE)
			nb_cmd++;
		// if (type[0] == PIPE)
		// 	return (ft_err_par(1), false);
		// else if (pre_type == PIPE && type[j] == PIPE)
		// 	return (ft_err_par(1), false);
		j++;
	}
	msh->tk_type = type;
	msh->nb_cmd = nb_cmd;
	return (true);
}

// t_type	*classify_token(char **tokens, int nb_tk)
// {
// 	t_type	*type;
// 	t_type	pre_type;
// 	int		command;
// 	int		j;
	
// 	type = (t_type *)malloc(sizeof(t_type) * (nb_tk + 1));
// 	if (!type)
// 		return (NULL);
// 	pre_type = VOID;
// 	command = 0;
// 	j = 0;
// 	while (j < nb_tk)
// 	{
// 		if (pre_type == PIPE)
// 			command = 0;
// 		type[j] = token_type(tokens[j], pre_type, &command);
// 		if (type[0] == PIPE)
// 			return (ft_err_par(1), NULL);
// 		else if (pre_type == PIPE && type[j] == PIPE)
// 			return (ft_err_par(1), NULL);
// 		pre_type = type[j];
// 		j++;
// 	}
// 	type[j] = VOID;
// 	return (type);
// }

// t_type	token_type(char *token, t_type pre_type, int *command)
// {
// 	if (*token == '<')
// 		return (RDRT_IN);
// 	else if (*token == '>')
// 		return (RDRT_OUT);
// 	else if (ft_ispipe(*token))
// 		return (PIPE);
// 	else if (pre_type == RDRT_IN || pre_type == RDRT_OUT)
// 		return (FILENAME);
// 	else if (*command == 0)
// 		return (*command = 1, COMMAND);
// 	else
// 		return (ARGUMENT);
// }
