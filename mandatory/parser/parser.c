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

t_rdrt	what_rdrt(char *token)
{
	t_rdrt	rdrt;

	if (token[0] == '<')
	{
		if (!token[1])
			rdrt = input;
		else if (token[1] && token[1] == '<')
			rdrt = heredoc;
	}
	else
	{
		if (!token[1])
			rdrt = output;
		else if (token[1] && token[1] == '>')
			rdrt = append;
	}
	return (rdrt);
}

bool	parsing_tokens(char **tokens, t_type *type, t_spcmd *spcmd, int *i)
{
	if (type[*i] == ARGUMENT)
		spcmd->arg[spcmd->nb.arg++] = ft_strdup(tokens[*i]);
	else if (type[*i] == RDRT_IN)
	{
		spcmd->in[spcmd->nb.in].rdrt = what_rdrt(tokens[(*i)++]);
		spcmd->in[spcmd->nb.in++].filename = ft_strdup(tokens[*i]);
	}
	else if (type[*i] == RDRT_OUT)
	{
		spcmd->out[spcmd->nb.out].rdrt = what_rdrt(tokens[(*i)++]);
		spcmd->out[spcmd->nb.out++].filename = ft_strdup(tokens[*i]);
	}
	return (true);
}

bool	parsing(t_msh *msh)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < msh->nb_cmd)
	{
		msh->spcmd[j].nb = (t_nb){0, 0, 0, 0};
		while (i < msh->nb_tk)
		{
			parsing_tokens(msh->tokens, msh->tk_type, &msh->spcmd[j], &i);
			if (msh->tk_type[i++] == PIPE)
			{
				msh->spcmd[j].nb.pipe = 1;
				break ;
			}
		}
		j++;
	}
	return (true);
}

bool	parser(t_msh *msh)
{
	if (!classify_token(msh))
		return (false);
	if (!valid_tokens(msh->tokens, msh->nb_tk, msh->tk_type))
		return (false);
	if (!allocate_spcmd(msh, msh->nb_cmd))
		return (false);
	// printf("Satu99\n");
	// printf("nb_cmd:%d\n", msh->nb_cmd);
	if (!allocate_sub_spcmd(msh->spcmd, msh->nb_cmd, msh->tk_type, msh->nb_tk))
		return (false);
	// printf("Satu99\n");
	if (!parsing(msh))
		return (false);
	// debug_type(msh->tk_type, msh->nb_tk, "Type");//debug
	return (true);
}
