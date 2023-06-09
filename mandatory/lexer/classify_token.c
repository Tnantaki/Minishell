#include "minishell.h"

// ### classify_token ###
// Will tag type to token
// type will classify by :
// - redirection
// - pipe
// - filename
// - argument

t_type	token_type(char *token, t_type pre_type)
{
	if (*token == '<' || *token == '>')
		return (e_rdrt);
	else if (*token == '|')
		return (e_pipe);
	else if (pre_type == e_rdrt)
		return (e_filename);
	else
		return (e_argument);
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
			type[j] = token_type(msh->tokens[j], e_void);
		else
			type[j] = token_type(msh->tokens[j], type[j - 1]);
		if (type[j] == e_pipe)
			nb_pipe++;
		j++;
	}
	msh->tk_type = type;
	msh->nb_pipe = nb_pipe;
	msh->nb_cmd = nb_pipe + 1;
	return (true);
}