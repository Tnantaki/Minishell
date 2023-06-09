#include "minishell.h"

void	err_tok(int errnum, char *rdrt)
{
	if (errnum == 1)
		printf("msh: syntax error near unexpected token `%s'\n", rdrt);
	if (errnum == 2)
		printf("msh: syntax error near unexpected token `newline'\n");
}

bool	valid_tokens(char **tokens, int nb_tk, t_type *type)
{
	int		i;
	t_type	pre;

	i = 0;
	pre = e_void;
	if (type[0] == e_pipe)
		return (err_tok(1, tokens[i]), false);
	if (type[nb_tk - 1] == e_rdrt)
		return (err_tok(2, NULL), false);
	while (i < nb_tk)
	{
		if ((type[i] == e_pipe || type[i] == e_rdrt)
				&& (pre == e_pipe || pre == e_rdrt))
			return (err_tok(1, tokens[i]), false);
		pre = type[i];
		i++;
	}
	return (true);
}
