/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:25:01 by tnantaki          #+#    #+#             */
/*   Updated: 2023/06/12 13:25:02 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	err_tok(int errnum, char *rdrt)
{
	if (errnum == 1)
	{
		ft_prterr("msh: syntax error near unexpected token `");
		ft_prterr(rdrt);
		ft_prterr("'\n");
	}
	if (errnum == 2)
		ft_prterr("msh: syntax error near unexpected token `newline'\n");
	g_status = 2;
}

bool	valid_tokens(char **tokens, int nb_tk, t_type *type)
{
	int		i;
	t_type	pre;

	i = 0;
	pre = e_void;
	if (type[0] == e_pipe)
		return (err_tok(1, tokens[i]), false);
	while (i < nb_tk)
	{
		if ((pre == e_pipe && type[i] == e_pipe)
			|| (pre == e_rdrt && type[i] == e_pipe)
			|| (pre == e_rdrt && type[i] == e_rdrt))
			return (err_tok(1, tokens[i]), false);
		pre = type[i];
		i++;
	}
	if (type[nb_tk - 1] == e_rdrt || type[nb_tk - 1] == e_pipe)
		return (err_tok(2, NULL), false);
	return (true);
}
