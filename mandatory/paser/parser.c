#include "minishell.h"

/*Parsing will interpret the tokens by tokens and Cut to
Simple command if it found Output Redirections
There are 3 Output Redirection
1. >  : Output
2. >> : Append Output
3. |  : Pipe */
bool	ft_is(char *token)
{
	if (c == ' ' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\r')
		return (true);
	return (false);
}

int	parser(char **tokens)
{
	int		j;
	t_spcmd	*spcmd;

	j = 0;
	while (tokens[j])
	{
		if (!cpcmd->rdrt && ft_isrdrt(tokens[j]))
		else if (!spcmd->cmd && ft_iscmd(tokens[j]))
			spcmd->cmd = tokens[j];
		else if (!cpcmd->arg && ft_isarg(tokens[j]))
		else if (!cpcmd->pipe && ft_ispipe(tokens[j]))
		if (cpcmd->pipe)
		j++;
	}
	// tokens = expander(tokens);
	checker_2d_arr(tokens, "Paser");//for debug
	return (0);
}
is_cmd
is_rdrt
is_pipe
is_arg
