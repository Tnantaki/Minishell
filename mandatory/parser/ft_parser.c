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

// char	**parse_arg(char **tokens, t_type *type, int *p)
// {
// 	int		i;
// 	int		arg_nb;
// 	char	**arg;

// 	arg_nb = 0;
// 	while (type[arg_nb] == ARGUMENT)
// 		arg_nb++;
// 	arg = (char **)malloc(sizeof(char *) * (arg_nb + 1));
// 	if (!arg)
// 		return (NULL);
// 	i = 0;
// 	while (type[*p] == ARGUMENT)
// 	{
// 		arg[i] = ft_strdup(tokens[(*p)++]);
// 		if (!arg[i])
// 			return (ft_free2d_nstr(arg, i));
// 		i++;
// 	}
// 	return (arg);
// }

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
				break ;
		}
		j++;
	}
	return (true);
}

int	*count_arg(t_type *type, int nb_tk, int nb_cmd)
{
	int	i;
	int	j;
	int	*nb_arg;

	nb_arg = (int *)ft_calloc(nb_cmd, sizeof(int));
	if (!nb_arg)
		return (NULL);
	i = 0;
	j = 0;
	while (i < nb_tk)
	{
		nb_arg[j] = 0;
		if (type[i++] == COMMAND)
		{
			while (type[i++] == ARGUMENT)
				(nb_arg[j])++;
		}
	}
	return (nb_arg);
}

bool	parser(t_msh *msh)
{
	if (!classify_token(msh))
		return (false);
	if (!allocate_spcmd(msh, msh->nb_cmd))
		return (false);
	if (!allocate_sub_spcmd(msh->spcmd, msh->nb_cmd, msh->tk_type, msh->nb_tk))
		return (false);
	// if (!allocate_input(msh))
	// 	return (false);
	// if (!allocate_output(msh))
	// 	return (false);
	if (!parsing(msh))
		return (false);
	debug_type(msh->tk_type, msh->nb_tk, "Type");//debug
	// if (!allocate_arg(msh));
	// 	return (false);
	// printf("nb_tk:%d\n", cmd_nb);
	// arg_nb = count_arg(type, nb_tk, cmd_nb);
	// printf("nb_cmd :%d\n", nb_cmd);
	// spcmd = parsing(tokens, type, msh->nb_tk, msh->nb_cmd);
	// msh->spcmd = spcmd;
	return (true);
}

// t_spcmd	*parsing(char **tokens, t_type *type, int nb_tk, int nb_cmd)
// {
// 	int		i;
// 	int		j;
// 	t_spcmd	*spcmd;

// 	spcmd = allocate_spcmd(nb_cmd);
// 	if (!spcmd)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	while (i < nb_tk)
// 	{
// 		if (type[i] == COMMAND)
// 		{
// 			spcmd[j].cmd = ft_strdup(tokens[i++]);
// 			printf("first:%d\n", i);
// 			spcmd[j].arg = parse_arg(tokens, type, &i);
// 		}
// 		else if (type[i] == PIPE)
// 		{
// 			spcmd[j++].pipe = 1;
// 			i++;
// 		}
// 		else if (type[i] == RDRT_IN)
// 			spcmd[j].in = parse_rdrt(tokens, &i);
// 		else if (type[i] == RDRT_OUT)
// 			spcmd[j].out = parse_rdrt(tokens, &i);
// 	}
// 	return (spcmd);
// }