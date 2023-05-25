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
				&& !(spcmd[i].in)) || (spcmd[i].nb.out && !(spcmd[i].out)))
			return (perror("Error malloc"), false);
		i++;
	}
	return (true);
}
