/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_lexer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:28:26 by tnantaki          #+#    #+#             */
/*   Updated: 2023/06/12 13:28:27 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_quote_len(char *str, int c)
{
	int	i;

	i = 1;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (i + 1);
	return (0);
}

int	ft_token_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_istoken(str[i]))
	{
		if (ft_isquote(str[i]))
			i += ft_quote_len(&str[i], str[i]);
		else
			i++;
	}
	return (i);
}

int	ft_optr_len(char *str)
{
	int	i;

	i = 1;
	if (str[i] == '<' || str[i] == '>')
		i++;
	return (i);
}

int	ft_cmd_len(char *str)
{
	int	i;

	i = 1;
	while (str[i] && ft_iscmd(str[i]))
		i++;
	return (i);
}

int	ft_var_len(char *line)
{
	int	i;

	i = 0;
	if (ft_is_1stvar(line[i]))
		i++;
	else
		return (0);
	while (line[i] && ft_isvar(line[i]))
		i++;
	return (i);
}
