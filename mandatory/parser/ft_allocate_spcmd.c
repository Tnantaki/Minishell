#include "minishell.h"

t_nb	count_struct_nb(t_type *type, int nb_tk, int *j)
{
	t_nb	nb;

	nb = (t_nb){0, 0, 0, 0};
	while (*j < nb_tk)
	{
		if (type[*j] == PIPE)
			return (nb.pipe++, (*j)++, nb);
		if (type[*j] == ARGUMENT)
			nb.arg++;
		if (type[*j] == RDRT_IN)
			nb.in++;
		if (type[*j] == RDRT_OUT)
			nb.out++;
		(*j)++;
	}
	return (nb);
}

bool	allocate_spcmd(t_msh *msh, int nb_cmd)
{
	t_spcmd	*spcmd;

	spcmd = (t_spcmd *)malloc(sizeof(t_spcmd) * (nb_cmd));
	if (!spcmd)
		return (perror("Error malloc"), false);
	msh->spcmd = spcmd;
	return (true);
}

bool	allocate_sub_spcmd(t_spcmd *spcmd, int nb_cmd, t_type *type, int nb_tk)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < nb_cmd)
	{
		spcmd[i] = (t_spcmd){.cmd = NULL, .arg = NULL, .in = NULL, .out = NULL};
		spcmd[i].nb = count_struct_nb(type, nb_tk, &j);
		if (spcmd[i].nb.arg)
		{
			spcmd[i].arg = malloc(sizeof(char *) * (spcmd[i].nb.arg + 1));
			spcmd[i].arg[spcmd[i].nb.arg] = NULL;
		}
		if (spcmd[i].nb.in)
			spcmd[i].in = malloc(sizeof(t_io) * (spcmd[i].nb.in));
		if (spcmd[i].nb.out)
			spcmd[i].out = malloc(sizeof(t_io) * (spcmd[i].nb.out));
		if ((spcmd[i].nb.arg && !(spcmd[i].arg)) || (spcmd[i].nb.in
				&& !(spcmd[i].in)) || (spcmd[i].nb.out && spcmd[i].out))
			return (perror("Error malloc"), false);
		i++;
	}
	return (true);
}

// bool	count_type_nb(t_msh *msh)
// {
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	while (i < msh->nb_cmd)
// 	{
// 		msh->spcmd[i].nb = count_struct_nb(msh->tk_type, msh->nb_cmd, &j);
// 		i++;
// 	}
// 	return (true);
// }

// int	count_type(t_type *type, int nb_cmd, t_type typecount, int *j)
// {
// 	int	nb;

// 	nb = 0;
// 	while (*j < nb_cmd)
// 	{
// 		if (type[*j] == PIPE)
// 			break ;
// 		if (type[*j] == typecount)
// 			nb++;
// 		(*j)++;
// 	}
// 	(*j)++;
// 	return (nb);
// }

// bool	allocate_arg(t_msh *msh)
// {
// 	int		i;
// 	int		j;
// 	int		nb_arg;

// 	i = 0;
// 	j = 0;
// 	while (i < msh->nb_cmd)
// 	{
// 		nb_arg = count_type(msh->tk_type, msh->nb_tk, ARGUMENT, &j);
// 		msh->spcmd[i].arg = (char **)malloc(sizeof(char *) * (nb_arg + 1));
// 		if (!(msh->spcmd[i].arg))
// 			return (perror("Error malloc"), false);
// 		msh->spcmd[i].arg[nb_arg] = NULL;
// 		i++;
// 	}
// 	return (true);
// }

// bool	allocate_input(t_msh *msh)
// {
// 	int		i;
// 	int		j;
// 	int		nb_input;

// 	i = 0;
// 	j = 0;
// 	while (i < msh->nb_cmd)
// 	{
// 		nb_input = count_type(msh->tk_type, msh->nb_tk, RDRT_IN, &j);
// 		msh->spcmd[i].nb_in = nb_input;
// 		msh->spcmd[i].in = (t_io *)malloc(sizeof(t_io) * (nb_input));
// 		if (!(msh->spcmd[i].in))
// 			return (perror("Error malloc"), false);
// 		i++;
// 	}
// 	return (true);
// }

// bool	allocate_output(t_msh *msh)
// {
// 	int		i;
// 	int		j;
// 	int		nb_output;

// 	i = 0;
// 	j = 0;
// 	while (i < msh->nb_cmd)
// 	{
// 		nb_output = count_type(msh->tk_type, msh->nb_tk, RDRT_IN, &j);
// 		msh->spcmd[i].nb_in = nb_output;
// 		msh->spcmd[i].out = (t_io *)malloc(sizeof(t_io) * (nb_output));
// 		if (!(msh->spcmd[i].in))
// 			return (perror("Error malloc"), false);
// 		i++;
// 	}
// 	return (true);
// }