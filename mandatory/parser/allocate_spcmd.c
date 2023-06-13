/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_spcmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:25:16 by tnantaki          #+#    #+#             */
/*   Updated: 2023/06/12 13:25:17 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_nb	count_struct_nb(t_type *type, int nb_tk, int *j)
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
	int		i;
	t_spcmd	*spcmd;

	spcmd = (t_spcmd *)malloc(sizeof(t_spcmd) * nb_cmd);
	if (!spcmd)
		return (perror("Error malloc"), false);
	i = 0;
	while (i < nb_cmd)
		spcmd[i++] = (t_spcmd){.arg = NULL, .io = NULL};
	msh->spcmd = spcmd;
	return (true);
}

void	null_filename(t_io *io, int nb_io)
{
	int	i;

	i = 0;
	if (!io)
		return ;
	while (i < nb_io)
		io[i++].filename = NULL;
}

bool	allocate_sub_spcmd(t_spcmd *spcmd, int nb_cmd, t_type *type, int nb_tk)
{
	int		j;
	int		i;

	j = 0;
	i = 0;
	while (j < nb_cmd)
	{
		spcmd[j].nb = count_struct_nb(type, nb_tk, &i);
		if (spcmd[j].nb.arg)
		{
			spcmd[j].arg = malloc(sizeof(char *) * (spcmd[j].nb.arg + 1));
			spcmd[j].arg[0] = NULL;
		}
		if (spcmd[j].nb.io)
		{
			spcmd[j].io = malloc(sizeof(t_io) * (spcmd[j].nb.io));
			null_filename(spcmd[j].io, spcmd[j].nb.io);
		}
		if ((spcmd[j].nb.arg && !(spcmd[j].arg))
			|| (spcmd[j].nb.io && !(spcmd[j].io)))
			return (perror("Error malloc"), false);
		j++;
	}
	return (true);
}

void	free_spcmd(t_spcmd *spcmd, int nb_cmd)
{
	int	j;
	int	i;

	j = 0;
	while (j < nb_cmd)
	{
		ft_free2dstr(spcmd[j].arg);
		if (spcmd[j].io)
		{
			i = 0;
			while (i < spcmd[j].nb.io)
				free(spcmd[j].io[i++].filename);
			free(spcmd[j].io);
		}
		j++;
	}
	free(spcmd);
}
