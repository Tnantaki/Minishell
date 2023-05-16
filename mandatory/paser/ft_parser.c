#include "minishell.h"

/*Parsing will interpret the tokens by tokens and Cut to
Simple command if it found Output Redirections
There are 3 Output Redirection
1. >  : Output
2. >> : Append Output
3. |  : Pipe */

// is_cmd
// is_rdrt
// is_pipe
// is_arg
bool	parser(char **tokens)
{
	// int		j;
	int		ct;
	t_type	*type;
	// t_spcmd	*spcmd;

	ct = ft_2d_strlen(tokens);
	type = classify_token(tokens, ct);
	debug_type(type, ct, "Type");//debug
	exit(0);
	// j = 0;
	// while (tokens[j])
	// {
		// if (!cpcmd->rdrt && ft_isrdrt(tokens[j]))
		// else if (!spcmd->cmd && ft_iscmd(tokens[j]))
		// 	spcmd->cmd = tokens[j];
		// else if (!cpcmd->arg && ft_isarg(tokens[j]))
		// else if (!cpcmd->pipe && ft_ispipe(tokens[j]))
		// if (cpcmd->pipe)
	// 	j++;
	// }
	// debug_tokens(tokens, "Paser");//for debug
	return (true);
}
