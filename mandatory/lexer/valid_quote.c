/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:24:56 by tnantaki          #+#    #+#             */
/*   Updated: 2023/06/12 13:24:57 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	err_unclosed_quote(int errnum)
{
	if (errnum == 1)
		ft_prterr("msh: syntax error unclosed single quote `\''\n");
	else if (errnum == 2)
		ft_prterr("msh: syntax error unclosed double quote `\"'\n");
	g_status = ES_ERROR;
	return (0);
}

// $ dollar signed
// statuc code = $?
// position argument = $1-9
// special var = $$, $#, $@, $-, $!, $*
// _, 1-9, a-z, A-Z
static int	ft_dollarlen(char *str)
{
	int	i;

	i = 1;
	if (!str[i])
		return (1);
	else if (str[i] == '?')
		i += 1;
	else if (ft_isdigit(str[i]))
		i += 1;
	else if (ft_isspecial(str[i]))
		i += 1;
	else if (ft_is_1stvar(str[i]))
		i += ft_var_len(&str[i]);
	return (i);
}

static int	is_unclosed_quote(char *str)
{
	int	len;

	len = 0;
	if (str[len] == '\'')
	{
		len = ft_quote_len(str, '\'');
		if (!len)
			return (err_unclosed_quote(1));
	}
	else
	{
		len = ft_quote_len(str, '\"');
		if (!len)
			return (err_unclosed_quote(2));
	}
	return (len);
}

bool	valid_quote(char *line)
{
	int		len;

	while (*line)
	{
		len = 0;
		while (*line && ft_isspace(*line))
			line++;
		if (!(*line))
			break ;
		else if (ft_isquote(*line))
			len = is_unclosed_quote(line);
		else if (ft_isoptr(*line))
			len = ft_optr_len(line);
		else if (*line == '$')
			len = ft_dollarlen(line);
		else if (ft_iscmd(*line))
			len = ft_cmd_len(line);
		if (!len)
			return (false);
		else
			line += len;
	}
	return (true);
}
