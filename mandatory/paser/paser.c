#include "minishell.h"

int	paser(char **tokens)
{
	tokens = expander(tokens);
	checker_2d_arr(tokens, "Paser");//for debug
	return (0);
}