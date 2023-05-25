#include "minishell.h"

void	err_par(int errnum, char *rdrt)
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
	pre = VOID;
	if (type[0] == PIPE)
		return (err_par(1, tokens[i]), false);
	if (type[nb_tk - 1] == RDRT_IN || type[nb_tk - 1] == RDRT_OUT)
		return (err_par(2, NULL), false);
	while (i < nb_tk)
	{
		if ((type[i] == PIPE || type[i] == RDRT_IN || type[i] == RDRT_OUT)
				&& (pre == PIPE || pre == RDRT_IN || pre == RDRT_OUT))
			return (err_par(1, tokens[i]), false);
		pre = type[i];
		i++;
	}
	return (true);
}