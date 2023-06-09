/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:25:26 by tnantaki          #+#    #+#             */
/*   Updated: 2023/06/12 13:25:27 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// Parsing will interpret the tokens by tokens and Cut to
// Simple command if it found Pipe

t_rdrt	what_rdrt(char *token)
{
	t_rdrt	rdrt;

	rdrt = 0;
	if (token[0] == '<')
	{
		if (!token[1])
			rdrt = e_input;
		else if (token[1] && token[1] == '<')
			rdrt = e_heredoc;
	}
	else
	{
		if (!token[1])
			rdrt = e_output;
		else if (token[1] && token[1] == '>')
			rdrt = e_append;
	}
	return (rdrt);
}

bool	parsing_tokens(char **tokens, t_type *type, t_spcmd *spcmd, int *i)
{
	if (type[*i] == e_argument)
	{
		spcmd->arg[spcmd->nb.arg] = ft_strdup(tokens[*i]);
		if (!spcmd->arg[spcmd->nb.arg++])
			return (false);
		spcmd->arg[spcmd->nb.arg] = NULL;
	}
	else if (type[*i] == e_rdrt)
	{
		spcmd->io[spcmd->nb.io].rdrt = what_rdrt(tokens[(*i)++]);
		spcmd->io[spcmd->nb.io].filename = ft_strdup(tokens[*i]);
		if (!spcmd->io[spcmd->nb.io].filename)
			return (false);
		spcmd->nb.io++;
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
		msh->spcmd[j].nb = (t_nb){0, 0, 0};
		while (i < msh->nb_tk)
		{
			if (!parsing_tokens(msh->tokens, msh->tk_type, &msh->spcmd[j], &i))
				return (perror("Error malloc"), false);
			if (msh->tk_type[i++] == e_pipe)
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
	if (!allocate_spcmd(msh, msh->nb_cmd))
		return (false);
	if (!allocate_sub_spcmd(msh->spcmd, msh->nb_cmd, msh->tk_type, msh->nb_tk))
		return (false);
	if (!parsing(msh))
		return (false);
	ft_free2dstr(msh->tokens);
	msh->tokens = NULL;
	free(msh->tk_type);
	msh->tk_type = NULL;
	return (true);
}
