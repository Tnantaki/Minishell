#include "minishell.h"

t_nb	count_struct_nb(t_type *type, int nb_tk, int *j)
{
	t_nb	nb;

	nb = (t_nb){0, 0, 0};
	while (*j < nb_tk)
	{
		if (type[*j] == e_pipe)
			return (nb.pipe++, (*j)++, nb);
		if (type[*j] == e_argument)
			nb.arg++;
		if (type[*j] == e_rdrt)
			nb.io++;
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
		spcmd[i] = (t_spcmd){.arg = NULL, .io = NULL};
		spcmd[i].nb = count_struct_nb(type, nb_tk, &j);
		if (spcmd[i].nb.arg)
		{
			spcmd[i].arg = malloc(sizeof(char *) * (spcmd[i].nb.arg + 1));
			spcmd[i].arg[spcmd[i].nb.arg] = NULL;
		}
		if (spcmd[i].nb.io)
			spcmd[i].io = malloc(sizeof(t_io) * (spcmd[i].nb.io));
		if ((spcmd[i].nb.arg && !(spcmd[i].arg))
			|| (spcmd[i].nb.io && !(spcmd[i].io)))
			return (perror("Error malloc"), false);
		i++;
	}
	return (true);
}
