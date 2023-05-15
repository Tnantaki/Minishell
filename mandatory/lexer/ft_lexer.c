#include "minishell.h"

bool	lexer(char *line, t_msh *msh)
{
	if (!valid_syntax(line))
		return (false);
	if (!tokenization(line, &msh->tokens))
		return (false);
	return (true);
}
