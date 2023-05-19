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

char	**parse_arg(char **tokens, t_type *type, int *p)
{
	int		i;
	int		arg_nb;
	char	**arg;

	arg_nb = 0;
	while (type[arg_nb] == ARGUMENT)
		arg_nb++;
	arg = (char **)malloc(sizeof(char *) * (arg_nb + 1));
	if (!arg)
		return (NULL);
	i = 0;
	while (type[*p] == ARGUMENT)
	{
		arg[i] = ft_strdup(tokens[(*p)++]);
		if (!arg[i])
			return (free2d_nstr(arg, i));
		i++;
	}
	return (arg);
}

t_io	parse_rdrt(char **tokens, int *p)
{
	t_io	io;

	io.have = 1;
	io.rdrt = what_rdrt(tokens[(*p)++]);
	io.filename = ft_strdup(tokens[(*p)++]);
	return (io);
}

t_spcmd *allocate_spcmd(int cmd_nb)
{
	int		i;
	t_spcmd	*spcmd;

	spcmd = (t_spcmd *)malloc(sizeof(t_spcmd) * (cmd_nb));
	if (!spcmd)
		return (NULL);
	i = 0;
	while (i < cmd_nb)
	{
		spcmd[i].cmd = NULL;
		spcmd[i].arg = NULL;
		spcmd[i].in.have = 0;
		spcmd[i].out.have = 0;
		spcmd[i].pipe = 0;
		i++;
	}
	return (spcmd);
}

t_spcmd	*parsing(char **tokens, t_type *type, int tk_nb, int cmd_nb)
{
	int		i;
	int		j;
	t_spcmd	*spcmd;

	spcmd = allocate_spcmd(cmd_nb);
	if (!spcmd)
		return (NULL);
	i = 0;
	j = 0;
	while (i < tk_nb)
	{
		if (type[i] == COMMAND)
		{
			spcmd[j].cmd = ft_strdup(tokens[i++]);
			printf("first:%d\n", i);
			spcmd[j].arg = parse_arg(tokens, type, &i);
		}
		else if (type[i] == PIPE)
		{
			spcmd[j++].pipe = 1;
			i++;
		}
		else if (type[i] == RDRT_IN)
			spcmd[j].in = parse_rdrt(tokens, &i);
		else if (type[i] == RDRT_OUT)
			spcmd[j].out = parse_rdrt(tokens, &i);
	}
	return (spcmd);
}

static int	count_cmd(t_type *type, int nb_tk)
{
	int	i;
	int	cmd_nb;

	i = 0;
	cmd_nb = 0;
	while (i < nb_tk)
	{
		if (type[i] == COMMAND)
			cmd_nb++;
		i++;
	}
	return (cmd_nb);
}

int	*count_arg(t_type *type, int nb_tk, int cmd_nb)
{
	int	i;
	int	j;
	int	*arg_nb;

	arg_nb = (int *)ft_calloc(cmd_nb, sizeof(int));
	if (!arg_nb)
		return (NULL);
	i = 0;
	j = 0;
	while (i < nb_tk)
	{
		arg_nb[j] = 0;
		if (type[i++] == COMMAND)
		{
			while (type[i++] == ARGUMENT)
				(arg_nb[j])++;
		}
	}
	return (arg_nb);
}

bool	parser(char **tokens, t_msh *msh)
{
	int		tk_nb;
	t_type	*type;
	t_spcmd	*spcmd;

	tk_nb = ft_2d_strlen(tokens);
	type = classify_token(tokens, tk_nb);
	msh->cmd_nb = count_cmd(type, tk_nb);
	// printf("tk_nb:%d\n", cmd_nb);
	// arg_nb = count_arg(type, tk_nb, cmd_nb);
	debug_type(type, tk_nb, "Type");//debug
	// printf("nb_cmd :%d\n", nb_cmd);
	spcmd = parsing(tokens, type, tk_nb, msh->cmd_nb);
	msh->spcmd = spcmd;
	return (true);
}
